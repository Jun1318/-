#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 30

void swap(int m[], int x, int y){
	int temp = m[x];
	m[x] = m[y];
	m[y] = temp;
}

void quick_sort(int m[], int first, int final){
	int position = first;
	if(first>=final)
		return;
	swap(m, first, (first+final)/2);
	for(int a=first+1;a<=final;a++)
		if(m[a]<m[first])
			swap(m, ++position, a);
	swap(m, first, position);
	quick_sort(m, first, position-1);
	quick_sort(m, position+1, final);
}

int main(void){
	srand(time(0));
	int m[MAX];
	for(int a=0;a<MAX;a++){
		m[a] = rand();
		printf("%d%c", m[a], (a%10==9)?'\n':'\t');
	}
	printf("\n\n");
	quick_sort(m, 0, MAX-1);
	for(int a=0;a<MAX;a++){
		m[a] = rand();
		printf("%d%c", m[a], (a%10==9)?'\n':'\t');
	}
}
