// 수정2 확장판

#include<stdio.h>

int tb[10001];
int n, temp;

int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &temp), tb[temp]++;
	
	for(int i=1; i<=10000; i++)
	if(tb[i]) while(tb[i]--) printf("%d\n", i);
}
