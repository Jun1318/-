#include<stdio.h>

void makeMagicSquare(int a[][100], int n){
	int col = n/2;
	int row = 0;
	
	for(int i=1;i<=n*n;i++){
		a[row][col] = i;
		int t_row = row-1;
		int t_col = col+1;
		if(t_row == -1)
			t_row = n-1;
		if(t_col == n)
			t_col = 0;
		if(a[t_row][t_col] != 0)
			row++;
		else
			row = t_row; col = t_col;
	}
}

void printMagicSquare(int a[][100], int n){
	int sum_col, sum_row;
	
	for(int i=0;i<n;i++){
		sum_col = 0;
		for(int j=0;j<n;j++){
			printf("%4d", a[i][j]);
			sum_col += a[i][j];
		}
		printf(":%4d", sum_col);
		printf("\n");
	}
	for(int i=0;i<n;i++)
		printf("  ..");
	printf("\n");
	
	for(int j=0;j<n;j++){
		sum_row = 0;
		for(int i=0;i<n;i++)
			sum_row += a[i][j];
		printf("%4d", sum_row);
	}
	printf("\n");
}

int main(void){
	int x,y,n;
	int a[100][100] = {0,};
	
	printf("홀수 마방진의 크기를 입력하세요 : ");
	scanf("%d", &n);
	
	makeMagicSquare(a,n);
	printMagicSquare(a,n);
}
