#include<stdio.h>
#define max 100
int main(void){
	int map[max][max] = {0,}, num;
	
	printf("홀수 입력 : ");
	scanf("%d", &num);
	
	int row = 0;
	int col = num/2;
	
	for(int i = 1; i<=num*num;i++){
		map[row][col] = i;
		int t_row = row-1;
		int t_col = col+1;
		if(t_row == -1)
			t_row = num-1;
		if(t_col == num)
			t_col = 0;
		if(map[t_row][t_col] !=0)
			row++;
		else{
			row = t_row;
			col = t_col;
		}
	}
	
	int sum_col;
	for(int i=0;i<num;i++){
		sum_col = 0;
		for(int j=0;j<num;j++){
			printf("%4d", map[i][j]);
			sum_col += map[i][j];
		}
		printf("->%4d", sum_col);
		printf("\n");
	}
}
