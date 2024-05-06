#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void){
	int memory[10], max, min, total=0;
	for(int a=0;a<10;a++){
		scanf("%d", &memory[a]);
		total += memory[a];
	}
	max = memory[0];
	min = memory[0];
	for(int a=1;a<10;a++){
		if(memory[a]>max)
			max = memory[a];
		if(memory[a]<min)
			min = memory[a];
	}
	printf("최대 : %d, 최소 : %d, 평균값 : %.2f", max, min, total/10.0);
}
