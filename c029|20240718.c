//https://www.acmicpc.net/problem/14460
#include<stdio.h>
#define TABLE_MAX 100000

int main(void){
	int table[TABLE_MAX][2];
	int num, diff, total=0;
	
	scanf("%d %d", &num, &diff);
	if(num<1 || num>TABLE_MAX)
		return 0;
	if(diff<0 || diff>=num)
		return 0;
		
	for(int i=0;i<num;i++)
		scanf("%d", &table[i][0]);
	for(int i=0;i<num;i++)
		scanf("%d", &table[i][1]);
		
	for(int i=0;i<num;i++){
		int temp_p1=0;
		
		while(table[i][0] !=table[temp_p1++][1]);
		
		for(int j=0;j<num;j++){
			int temp_p2=0;
			
			if(table[j][0] == table[i][0])
				continue;
			while(table[j][0] !=table[temp_p2++][1]);
			if((j>i && temp_p1>temp_p2) || (j<i && temp_p1<temp_p2))
				if(table[i][0]-table[i][1]>diff || table[i][0]-table[i][1]<-diff)
					total++;
		}
	}
	
	printf("%d", total/2);
}
