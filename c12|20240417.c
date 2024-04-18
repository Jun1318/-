//https://www.acmicpc.net/problem/1546
#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b){
	return(*(int*)b - *(int*)a);
}

int main(void){
	int repeat;
	float total=0.0;
	scanf("%d", &repeat);
	int memory[repeat];
	for(int a=0;a<repeat;a++)
		scanf("%d", &memory[a]);
	qsort(memory, repeat, sizeof(int), compare);
	for(int b=1;b<repeat;b++)
		total += (float)memory[b] / memory[0] * 100;
	printf("%f", (total+memory[0])/repeat);
	return 0;
}
