// 그냥 qsort

#include<stdio.h>
#include<stdlib.h>

int tb[1000];
int n;

int compare(const void *a, const void *b){return *(int*)a - *(int*)b;}

int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &tb[i]);
	
	qsort(tb, n, 4, compare);
	
	for(int i=0; i<n; i++) printf("%d\n", tb[i]);
}
