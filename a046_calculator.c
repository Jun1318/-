#include<stdio.h>

float add(float a, float b){
	return a+b;
}

float subtract(float a, float b){
	return a-b;
}

float multiply(float a, float b){
	return a*b;
}

float divide(float a, float b){
	return a/b;
}

int main(void){
	int type;
	float (*ptr[4])(float, float) = {add, subtract, multiply, divide}, a, b;
	
	printf("계산하려고 하는 실수 2개 입력 : ");
	scanf("%f %f", &a, &b);
	printf("원하는 계산 부호 선택 || 0:덧셈 1:뺴기 2:곱셈 3:나눗셈 : ");
	scanf("%d", &type);
	
	printf("결과값 : %.4f", ptr[type](a, b));
}
