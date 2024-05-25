#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define CNT 100
#define MAX 10000
int compare(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}
int main(void){
	int memory[CNT], value, index = 0;
	srand(time(0));
	
	for(int a=0;a<CNT;a++)	
		memory[a] = rand()%MAX;
		
	qsort(memory, CNT, sizeof(int), compare);
	
	int max = CNT -1, min =0;
	for(int a=0;a<CNT;a++)	
		printf("%d%c", memory[a], (a%13 == 12)?'\n': ' ');
		
	printf("\n찾으려는 숫자 입력 : ");
	scanf("%d", &value);
	while(max >= min){
		int mid = (max+min)/2;
		if(memory[mid] == value){
			printf("값 존재");
			index = -1;
			break; 
		}
		if(value<memory[mid])	max = mid-1;
		else if(value>memory[mid]) min = mid+1;
	} 
	
	if(index == 0)	printf("입력한 값 없음");
}
