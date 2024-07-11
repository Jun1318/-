#include<stdio.h>
int main(void){
	int n;
	
	printf("홀수 n을 입력하세요 : ");
	scanf("%d", &n);
	
	for(int i=0;i<n/2;i++){
		for(int j=0;j<i;j++)
			printf("%c", 'O');
		printf("%c", 'X');
		for(int j=0;j<n-2*(i+1);j++)
			printf("%c", 'O');
		printf("%c", 'X');
		for(int j=0;j<i;j++)
			printf("%c", 'O');
		printf("\n");
	}
	
	for(int j=0;j<n/2;j++)
		printf("%c", 'O');
	printf("%c", 'X');
	for(int j=0;j<n/2;j++)
		printf("%c", 'O');
	printf("\n");
		
	for(int i=n/2-1;i>=0;i--){
		for(int j=0;j<i;j++)
			printf("%c", 'O');
		printf("%c", 'X');
		for(int j=0;j<n-2*(i+1);j++)
			printf("%c", 'O');
		printf("%c", 'X');
		for(int j=0;j<i;j++)
			printf("%c", 'O');
		printf("\n");
	}
}
