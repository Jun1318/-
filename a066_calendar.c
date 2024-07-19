#include<stdio.h>

int zeller(int year, int month, int day){
	int w;
	
	if(month <=2){
		year--;
		month +=12;
	}
	
	w =(year+ year/4 -year/100 +year/400 +(13*month+8)/5 +day)%7;
	return w;
}

void printCalendar(int year, int month, int w){
	int day[2][13]={
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},};
	
	int leap = year%4 == 0&&year %100 !=0 || year%400 ==0;
	for(int i=0;i<w;i++)
		printf("\t");
	for(int d=1;d<day[leap][month];d++){
		printf("%2d\t", d);
		if((d+w)%7==0)
			printf("\n");
	}
	printf("\n");
}

void printWeekDays(void){
	char dayOfWeek[7][3] ={"일", "월", "화", "수", "목", "금", "토"};
	
	for(int i=0;i<7;i++)
		printf("%s\t", dayOfWeek[i]);
	printf("\n");
}

int main(void){
	int year, month, w;
	
	while(1){
		printf("=>년도와 월을 입력하세요 : ");
		scanf("%d %d", &year, &month);
		printWeekDays();
		w = zeller(year, month, 1);
		printCalendar(year, month, w);
	}
}
