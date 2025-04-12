// 그냥 브루트포스

#include<stdio.h>
#include<stdlib.h>

int tb[9];
int total;

int compare(const void *a, const void *b){return *(int*)a - *(int*)b;}

int main(void){
	for(int i=0; i<9; i++) scanf("%d", &tb[i]), total += tb[i];
	
	qsort(tb, 9, 4, compare);
	
	for(int i=0; i<8; i++)
	for(int j=i+1; j<9; j++)
	if(total -tb[i] -tb[j] == 100){
		for(int k=0; k<9; k++) if(k != i && k != j) printf("%d\n", tb[k]);
		return 0;
	}
}
