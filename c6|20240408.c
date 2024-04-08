//https://www.acmicpc.net/problem/2739
#include<stdio.h>
int main(void){
	int num;
	scanf("%d", &num);
	for(int a=1;a<10;a++)
		printf("%d X %d = %d\n", num, a, num*a);
	return 0;
}
