#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 30

void swap(int a[], int x, int y){
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

void bubble_sort(int a[], int min, int max){
	for(int x=0;x<max-1;x++)
		for(int y=0;y<max-1-x;y++)
			if(a[y] > a[y+1])
				swap(a, y, y+1);
}
int main(void){
	srand(time(0));
	int data[MAX];
	
	for(int a=0;a<MAX;a++)
		data[a] = rand();
		
	for(int a=0;a<MAX;a++)
		printf("%d%c", data[a], (a%12 == 11)?'\n':' ');
	printf("\n\n");
		
	bubble_sort(data, 0, MAX);
	
	for(int a=0;a<MAX;a++)
		printf("%d%c", data[a], (a%12 == 11)?'\n':' ');
}
