#include<stdio.h>
int gcd(int a, int b);
int main(void){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("두 수의 최대공약수  : %d, 최소공배수 : %d", gcd(a, b), a*b/gcd(a, b));
}
int gcd(int a, int b){
	if(b == 0) 	return a;
	else return gcd(b, a%b);
}
