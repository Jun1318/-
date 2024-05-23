#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10000
#define CNT 1000
void swap(int array[], int a, int b){
	int temp;
	temp = *(array+a);
	*(array+a) = *(array+b);
	*(array+b) = temp;
}
void sort(int array[], int size){
	for(int a=0;a<size;a++)
		for(int b=0;b<size-1;b++)
			if(*(array+b)>*(array+b+1))
				swap(array, b, b+1);
}
int main(void){
	srand(time(0));
	int a[CNT];
	int value, index=0;
	for(int i=0;i<CNT;i++)
		a[i] = rand()%MAX;
	sort(a, CNT);
	for(int i=0;i<CNT;i++)	printf("%6d%c", a[i], (i%10 == 9)?'\n':' ');
	int high = CNT-1, low = 0, mid;
	printf("찾으실 값을 입력하세요 :");
	scanf("%d", &value);
	while(low<=high){
		mid = (low + high) / 2;
		if(a[mid] == value){
			printf("입력하신 값 있음 - a[%d]", mid);
			index = -1;
			break;
		}
		if(value > a[mid])	low = mid+1;
		else high = mid-1;
	}
	if(index != -1)		printf("값 없음");
}
