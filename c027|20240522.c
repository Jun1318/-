//https://www.acmicpc.net/problem/10828
#include <stdio.h>
#include<string.h>
#define size 100
typedef struct{
	int data[size];
	int first, final;
}s_main;

void start(s_main *s_pointer){
	s_pointer->first = -1;
	s_pointer->final = -1;
}

int is_empty(s_main *s_pointer){ // 비었으면 1
	return s_pointer->first == s_pointer->final;
}

int is_full(s_main *s_pointer){ // 공간 있으면 0 반환 
	return s_pointer->final == size-1;
}

int s_size(s_main *s_pointer){
	return s_pointer->final - s_pointer->first;
}

void push(s_main *s_pointer, int n){
	if(is_full(s_pointer) != 1){
		s_pointer->final++;
		s_pointer->data[s_pointer->final] = n;
	}
}

int pop(s_main *s_pointer){
	if(is_empty(s_pointer) != 1){
		return s_pointer->data[s_pointer->final--];
	}
	return -1;
}

int top(s_main *s_pointer){
	if(is_empty(s_pointer) != 1){
		return s_pointer->data[s_pointer->final];
	}
	return -1;
}

int main(void) {	
	s_main s;
	start(&s);
	int input, memory[100], count=0, i;
	char order[15];
	scanf("%d", &input);
	for(int a=0;a<input;a++){
		scanf("%s", order);
		if(strcmp(order, "push") == 0){
			scanf("%d", &i);
			push(&s, i);
		}
		else if(strcmp(order, "pop") == 0)	memory[count++] = pop(&s);
		else if(strcmp(order, "size") == 0)	memory[count++] = s_size(&s);
		else if(strcmp(order, "empty") == 0)	memory[count++] = is_empty(&s);
		else if(strcmp(order, "top") == 0)	memory[count++] = top(&s);
	}
	for(int a=0;a<count;a++)	printf("%d\n", memory[a]);
}
