#include <stdio.h>
int data[100]={1,1};
int Fibonacci(int n){
	if(n == 0)	return 1;
	if(n == 1)	return 1;
	if(data[n] != 0)	return data[n];
	else return data[n] = Fibonacci(n-1) + Fibonacci(n-2); 
}
int main(void) {	
	int input;
	scanf("%d", &input);
	Fibonacci(input);
	for(int a=0;a<input;a++)	printf("%d ", data[a]);
}
