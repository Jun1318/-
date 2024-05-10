#include<stdio.h>
#include<stdbool.h>
int main(void){
	bool memory[1000];
	int prime=0;
	memory[0] = memory[1] = false;
	for(int a=2;a<1000;a++)	memory[a] = true;
	for(int a=2;a<1000;a++)	for(int b=2;b*a<=1000;b++)	memory[b*a] = false;
	for(int a=0;a<1000;a++){
		if(memory[a] == true){
			printf("%d%c", a, prime%15 ==0?'\n':' ');
			prime++;
		}
	}
	printf("\n소수 총합 : %d", prime);
}
