#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
	int memory[52] = {0,}, random_num;
	srand(time(0));
	for(int a=0;a<52;a++){
		do{
			random_num = rand()%52;
		}while(memory[random_num] != 0);
		memory[random_num] = 1;
		if(random_num/13 == 0)	printf("클로버 %d\n", random_num%13+1);
		else if(random_num/13 == 1)	printf("하트  %d\n", random_num%13+1);
		else if(random_num/13 == 2)	printf("스페이드  %d\n", random_num%13+1);
		else if(random_num/13 == 3)	printf("다이아몬드  %d\n", random_num%13+1);
	}
	return 0;
}
