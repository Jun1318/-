#include<stdio.h>
#include<stdlib.h>
struct student{
	int id;
	int score;
};
void print(struct student a[], int i){
	for(int b=0;b<i;b++)	printf("%d = %d\n", a[b].id, a[b].score);
	printf("\n");
}
int compare1(const void* b, const void *c){
	return ((struct student*)b)->id - ((struct student*)c)->id;
}

int compare2(const void* b, const void* c){
	return ((struct student*)b)->score - ((struct student*)c)->score;
}

int main(void){
	struct student a[] = {{1, 80}, {2, 75}, {3, 100}};
	qsort(a, 3, sizeof(struct student), compare1);
	print(a, 3);
	qsort(a, 3, sizeof(struct student), compare2);
	print(a, 3);
}
