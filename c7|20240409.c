#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b) {
		return(*(int*)b - *(int*)a);
	}
	
int main(void){
	int sum = 0, num;
	scanf("%d", &num);
	
	int tips[num];
	for(int c=0;c<num;c++)
		scanf("%d", &tips[c]);
	qsort(tips, num, sizeof(int), compare);
	
	for(int d=0; d<num;d++){
		if(tips[d]-d<0)
			break;
		sum += tips[d] - d;
	}
	
	printf("%d", sum);
	return 0;
}
