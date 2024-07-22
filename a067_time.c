#include<stdio.h>
#include<time.h>
#include<string.h>

void printDayTime(struct tm* t){
	char week[][3] = {"일", "월", "화", "수", "목", "금", "토"};
	char ampm[5] = "오전";
	
	if(t->tm_hour>12){
		t->tm_hour -= 12;
		strcpy(ampm, "오후");
	}
	
	printf("%d년 %2.d월 %2.d일 %s요일 %s %2d:%2.d:%2d\n", t->tm_year+1900, t->tm_mon+1, t->tm_mday, week[t->tm_wday], ampm, t->tm_hour, t->tm_min, t->tm_sec);
} 

int main(void){
	struct tm* t;
	time_t now;
	
	time(&now);
	printf("time = %ul\n", now);
	
	t = localtime(&now);
	printf("asctime = %s", asctime(t));
	
	printDayTime(t);
}
