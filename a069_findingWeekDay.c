#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct{
	int year, month, day;
}sDay;

bool isLeapYear(int year){
	return year%4 ==0 && (year%100 !=0 || year%400 ==0);
}

int dayOfYear(int y, int m, int d){
	int mDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int days =0, i;
	
	for(i=1; i<m; i++)
		days += d;
	return isLeapYear(y) && m>2 ? days+1 : days;
}

int calTotalDays(sDay *base, sDay *the){
	int totalDays =0, y;
	
	if(base->year != the->year){
		totalDays += dayOfYear(the->year, the->month, the->day);
		int yearDays = isLeapYear(base->year)? 366: 365;
		totalDays += yearDays - dayOfYear(base->year, base->month, base->day);
		for(y = base->year+1; y<the->year; y++)
			totalDays += isLeapYear(y)? 366: 365;
	}else
		totalDays = dayOfYear(the->year, the->month, the->day) - dayOfYear(base->year, base->month, base->day);
	
	return totalDays;
}

int main(void){
	sDay baseDay = {1900, 1, 1};
	sDay theDay;
	int tYear, tMonth, tDay;
	int totalDays =0;
	char week[][3] = {"일", "월", "화", "수", "목", "금", "토"};
	
	printf("요일을 알고 싶은 날짜를 입력하세요(연 월 일):");
	scanf("%d%d%d", &theDay.year, &theDay.month, &theDay.day);
	
	totalDays = calTotalDays(&baseDay, &theDay);
	printf("total days from 1900/1/1 : %d\n", totalDays);
	
	printf("%d년 %d월 %d일 = %s요일\n", theDay.year, theDay.month, theDay.day, week[(1+totalDays%7)%7]);
	
}
