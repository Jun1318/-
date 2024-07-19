#include<stdio.h>
#define MAX 100

int shell_max[MAX][MAX];

int shell_calculate(int x, int y){
	int dp[MAX][MAX] ={0};
	
	dp[x-1][y-1] = shell_max[x-1][y-1];
	for(int i=x-1;i>=0;i--)
		for(int j=y-1;j>=0;j--){
			if(i == x-1 && j == y-1)
				continue;
			if(i == x-1)
				dp[i][j] = shell_max[i][j] + dp[i][j+1];
			else if(j == y-1)
				dp[i][j] = shell_max[i][j] + dp[i+1][j];
			else
				dp[i][j] = shell_max[i][j] + ((dp[i+1][j]>dp[i][j+1])?dp[i+1][j]:dp[i][j+1]);
		}
	return dp[0][0];
}

int shell_count(int n){
	int total =0;
	
	for(int i=n;i>0;i--)
		for(int j=n;j>0;j--)
			total += shell_calculate(i, j);
	
	return total;
}

int main(void){
	char update;
	int x, y, num;
	int result[MAX]={0,};
	
	scanf("%d", &num);
	
	for(int i=0;i<num;i++)
		for(int j=0;j<num;j++)
			scanf("%d", &shell_max[i][j]);
	
	result[0] = shell_count(num);
	
	for(int i=1;i<=num;i++){
		scanf(" %c %d %d", &update, &x, &y);
		
		switch(update){
			case 'U':
				shell_max[x-1][y-1]++;
				result[i] = shell_count(num);
				break;
			case 'D':
				shell_max[x-1][y-1]--;
				result[i] = shell_count(num);
				break;
		}
	}
	
	for(int i=0;i<=num;i++)
		printf("%d\n", result[i]);
}
