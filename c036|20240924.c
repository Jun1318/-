//https://www.acmicpc.net/problem/11866
#include<stdio.h>
#define MAX 1000

int main(void){
	int n, dist, a[MAX*MAX], front =0, end;
	
	scanf("%d%d", &n, &dist);
	for(int i=0; i<n; i++)	a[i] = i+1;
	end = n;
	
	for(int j=dist-1; j>0; j--)
	a[end++] = a[front++];
		
	printf("<%d", a[front]);
	front++;
	
	for(int i=n-1; i>0; i--){
		for(int j=dist-1; j>0; j--)
			a[end++] = a[front++];
		
		printf(", %d", a[front]);
		front++;
	}
	
	printf(">");
}
