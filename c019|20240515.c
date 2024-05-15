//문제 : https://www.acmicpc.net/problem/1158
#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
int main(void){
	int person_number, random_num;
	bool memory[5000] = {0,};
	scanf("%d", &person_number);
	srand((unsigned)time(NULL));
	for(int a=0;a<person_number;){
		random_num = rand()%person_number;
		if(memory[random_num] == false){
			memory[random_num] = true;
			printf("%d%c", random_num+1, (a%15  == 14)?'\n':'\t');
			a++;	
		}
	}
}
