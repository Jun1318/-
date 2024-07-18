#include<stdio.h>
#define TABLE_MAX 100000

int main(void){
	int table[TABLE_MAX][2];
	int num, diff, count=0;
	
	scanf("%d %d", &num, &diff);
	
	for(int i=0;i<num;i++)
		scanf("%d", &table[i][0]);
	for(int i=0;i<num;i++)
		scanf("%d", &table[i][1]);
		
	for(int i=0;i<num;i++)
		if(table[i][0]-table[i][1]>diff || table[i][0]-table[i][1]<-diff)
			count++;
	
	printf("%d", count);
}
