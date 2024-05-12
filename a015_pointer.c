#include<stdio.h>
int main(void){
	int memory[4] = {1,2,3};
	int *pointer = &memory[0];
	while(*pointer != 0)	printf("[%p] = %d\n", pointer, *(pointer++));
}
