//https://www.acmicpc.net/problem/1929
#include<stdio.h>
#include<stdlib.h>
#define except 1000001

int compare(const void* a, const void* b){
	return(*(int*)a-*(int*)b);
}

int main(void){
	int x, y, count=0;
	scanf("%d %d", &x, &y);
	int memory[y];
	for(int a=0;a<y;a++)
		memory[a] = a+1;
	if(y==1)
		return 0;
	memory[0] = except;
	for(int b=2;b<=y;b++){
		for(count = 0;count<y;count++){
			if(memory[count]>b && memory[count] % b == 0)
				memory[count] = except;
			if(memory[count] < x)
				memory[count] = except;
		}
	}
	qsort(memory, y, 4, compare);
	count = 0;
	while(memory[count] != except){
		printf("%d\n", memory[count]);
		count++;
	}
	return 0;
}
