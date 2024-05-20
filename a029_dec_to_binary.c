#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
int check_overflow(char*);
void calculate_1(char*);
void calculate_2(int);
int main(void){
	char input[11];
	scanf("%s", input);
	if(check_overflow(input)){
		printf("정수의 범위를 벗어납니다.\n");
		exit(0);
	}
	printf("%s의 2진수형태 :", input);
	calculate_1(input);
	int temp = atoi(input);
	printf("\n%d의 2진수 형태 :", temp);
	calculate_2(temp);
}
int check_overflow(char m[]){
	char intmax[11];
	_itoa(INT_MAX, intmax, 10);
	if(strlen(m)>10)	return 1;
	else if(strlen(m) == 10){
		for(int a=0;a<10;a++){
			if(m[a] > intmax[a])	return 1;
		}
	}
	return 0;
}
void calculate_1(char m[]){
	int change_m = atoi(m), total[32] = {0}, a;
	for(a=0;change_m != 0;a++){
		total[a] = change_m %2;
		change_m /= 2;
	}
	for(;a>=0;a--)	printf("%d", total[a]);
	
}
void calculate_2(int i){
	if(i>=2)	calculate_2(i/2);
	printf("%d", i%2);
}
