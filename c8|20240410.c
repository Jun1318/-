//https://www.acmicpc.net/problem/10804
#include<stdio.h>
#include<stdlib.h>

int compareup(const void *a, const void *b){ // 배열 오름차순 정렬 
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if(num1 == num2)
		return 0;
	else if(num1 > num2)
		return 1;
	else
		return -1;
}

int comparedown(const void *a, const void *b){ // 배열 내림차순 정렬 
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if(num1 == num2)
		return 0;
	else if(num1 < num2)
		return 1;
	else
		return -1;
}

int main(void){
	int x, y;
	int memory[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};  
	int temp[20]; // 임시 저장소 
	for(int a=0;a<10;a++){
		scanf("%d %d", &x, &y); // 3,5
		
		for(int b=0;b<y-x;b++) // b<3 
			temp[b] = memory[x+b]; // temp[1] == memory[4]
			
		if(temp[0]<temp[1])
			qsort(temp, y-x, sizeof(int), comparedown);
		else
			qsort(temp, y-x, sizeof(int), compareup);
		
		for(int c=0;c<y-x;c++)
			memory[x+c] = temp[c];
	}
	for(int d=0;d<20;d++)
		printf("%d ", memory[d]);
		
	return 0;
}
