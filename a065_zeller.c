#include<stdio.h>
int main(void){
	int year, month, day, w;
	char dayOfWeek[7][3] = {"일", "월", "화", "수", "목", "금", "토"};
	
	printf("년 월 일 입력 : ");
	scanf("%d %d %d", &year, &month, &day);
	
	if(month <=2){
		year-= 1;
		month +=12;
	}
	
	w = (year +year / 4 - year / 100 + year / 400 + (13 *month + 8) / 5 +day)%7;
	
	printf("%s요일\n", dayOfWeek[w]);
}
