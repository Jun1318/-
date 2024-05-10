#include<stdio.h>
int determine(int, int*);

int main(void){
	int total=0;
	for(int x=2;x<=1000;x++)	if(!determine(x, &total))	printf("%d%c", x, total%15 == 0?'\n':' ');
	printf("\n소수 총합 : %d", total);
	return 0;
}

int determine(int a, int *b){
	for(int x=2;x<a;x++)	if(a%x==0)	return 1;
	*b += 1;
	return 0;
}
