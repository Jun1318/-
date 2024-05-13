#include<stdio.h>
int add(int* p){return *(p)+*(p+1)+*(p+2);}
int main(void){
	int memory[3] = {1,2,3};
	int* p = memory;
	printf("%d, %d", add(memory), *p++);
}
