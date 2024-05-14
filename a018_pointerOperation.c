#include<stdio.h>
int main(void){
	int memory[5] = {1,2,3,4,5};
	int *p1 = memory;
	int *p2 = &memory[4];
	printf("%d\n", *(++p1));
	printf("%d", p2 - p1);
}
