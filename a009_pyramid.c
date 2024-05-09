#include<stdio.h>
int main(void){
	for(int a=5;a>0;a--){
		for(int b=1;b<a;b++)	printf(" ");
		for(int c=0;c<11-2*a;c++)	printf("*");
		printf("\n");
	}
	return 0; 
}
