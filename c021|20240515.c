//문제 : https://www.acmicpc.net/problem/1158
#include<stdio.h>
#include<stdbool.h>
int main(void){
	bool memory[5000] = {0,};
	int total_num, pre_num, start_num, num, count=0;
	scanf("%d %d%*c", &total_num, &start_num); // 7 3
	pre_num = start_num; // 3 3
	do{
		printf("%d\t", pre_num); // 3
		memory[pre_num-1] = true; // memory[2] = 1
		num = 0; 
		count++;
		for(int a=0;a<start_num;){
			(++pre_num > total_num)? pre_num = 1 : 0;
			if(memory[pre_num-1] == false)	a++;
			if(++num > total_num*4)	break; 
		}
	}while(count < total_num);
}
