#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 30
void swap(int m[], int x, int y){
	int temp = m[x];
	m[x] = m[y];
	m[y] = temp;
}
void selection_sort(int m[], int final){
	int min;
	for(int a=0;a<final;a++){
		min = a;
		for(int b=a;b<30;b++)
			if(m[b]<m[min])
				min = b;
		swap(m, a, min);
	}
}
int main(void){
	int m[MAX];
	srand(time(0));
	for(int a=0;a<MAX;a++){
		m[a] = rand();
		printf("%d%c", m[a], (a%10==9)?'\n':'\t');
	}
	printf("\n\n");
	selection_sort(m, MAX);
	for(int a=0;a<MAX;a++)
		printf("%d%c", m[a], (a%10==9)?'\n':'\t');
}
