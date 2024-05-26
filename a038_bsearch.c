#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}
int main(void){
	int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int* ptr;
	int key; 
	size_t size = sizeof(a) / sizeof(a[0]);
	
	printf("찾으려는 값을 입력하세요 :");
	scanf("%d", &key);
	
	ptr = (int*)bsearch(&key, a, size, sizeof(int), compare);
	
	if(ptr != NULL)	printf("값 %d는 a[%d]에 있습니다", *ptr, ptr-a);
	else printf("찾는 값 없음");
}
