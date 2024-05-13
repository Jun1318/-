#include<stdio.h>
void swap(int*, int*);
int main(void){
	int x, y;
	scanf("%d%*c%d", &x, &y);
	swap(&x, &y);
	printf("%d %d\n", x, y);
}
void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
