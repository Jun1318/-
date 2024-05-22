//https://www.acmicpc.net/problem/10845
#include <stdio.h>
#include<string.h>
#define size 100

typedef struct{
	int memory[size];
	int first, final;
}q_main;

void start(q_main *q_pointer){ // first final 초기화 
	q_pointer->first = -1;
	q_pointer->final = -1;
}

int is_empty(q_main *q_pointer){ // first == final 이면 1 반환, 다르면 0 반환 
	return q_pointer->first == q_pointer->final;
}

int is_full(q_main *q_pointer){ // final이 99면 1 반환(꽉 찻다는거), 다르면 0 반환 
	return q_pointer->final == size-1;
}

void input(q_main *q_pointer, int n){ // 공간 남아있으면 final 증가 시키고 memory[final]에 입력 받은 정수 입력 
	if(is_full(q_pointer) != 1){
		q_pointer->final++;
		q_pointer->memory[q_pointer->final] = n;	
	}
}

int size_calculate(q_main *q_pointer){ // final - first 반환 
	return q_pointer->final - q_pointer->first;
}

int pop(q_main *q_pointer){ // 
	if(is_empty(q_pointer))	return -1;
	else{
		q_pointer->first++;
		return q_pointer->memory[q_pointer->first];
	}
}

int main(void) {
	q_main q;
	start(&q);
	int i, count=0, n, data[1000000];
	char order[20];
	scanf("%d", &i);
	for(int a=0;a<i;a++){
		scanf("%s", order);
		if(strcmp(order, "push")==0){
			scanf("%d", &n);
			input(&q, n);
		}
		else if(strcmp(order, "pop")==0)	data[count++] = pop(&q);
		else if(strcmp(order, "size")==0)	data[count++] = size_calculate(&q);
		else if(strcmp(order, "empty")==0)	data[count++] = is_empty(&q);
		else if(strcmp(order, "front")==0)	data[count++] = (is_empty(&q))?-1:q.memory[q.first +1];
		else if(strcmp(order, "back")==0)	data[count++] = (is_empty(&q))?-1:q.memory[q.final];
	} 
	for(int a=0;a<count;a++)	printf("%d\n", data[a]);
}
