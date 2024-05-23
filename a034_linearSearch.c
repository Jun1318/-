#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 10000
#define CNT 1000
int main(void){
	int a[CNT];
	int value, index=0, max=0, min=0;
	srand(time(0));
	for(int b=0;b<CNT;b++){
		a[b] = rand()%MAX;
		printf("%d%c", a[b], (b%10 == 9)?'\n':' ');
		if(max<a[b])	max = a[b];
		if(min>a[b])	min = a[b];
	}
	printf("\n\nmax : %d, min : %d\n", max, min);
	
	printf("\n찾고자 하는 값 입력 :");
	scanf("%d", &value);
	for(int b=0;b<CNT;b++){
		if(a[b] == value){
			printf("값 있음");
			index = -1;
			break; 
		}
	}
	if(index != -1)	printf("값 없음");
}
