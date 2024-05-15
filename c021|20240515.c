//문제 : https://www.acmicpc.net/problem/1158
#include<stdio.h>
#include<stdbool.h>
int main(void){
	bool memory[5000] = {0,};
	int person_num, start_num, present_num,count=0, roll;
	scanf("%d%*c%d", &person_num, &start_num); // 7 3
	present_num = start_num-1; // 2 2
	for(int a=0;count<person_num;a++){ // 0 < 7
		roll = 0;
		for(int b=0;b<start_num;){
			(++present_num == person_num)? present_num = 0 : 0;
			if(memory[present_num] == 0)	b++;
			roll++;
			if(roll > person_num)	break;
		}
		count++;
		printf("%d%c", present_num+1, (a%15 == 14)?'\n':'\t');
	}
}
