#include<stdio.h>

int add(int a, int b){
	return a+b;
}

void printf_H(void){
	printf("Hello\n");
}

int main(void){
	int (*ptr)(int, int) = add, b, c;
	void (*fptr)() = printf_H;
	
	printf("정수 2개 입력 :");
	scanf("%d %d", &b, &c);
	
	printf("%d + %d = %d\n", b, c, ptr(b,c));
	fptr();
}
