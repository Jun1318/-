//https://www.acmicpc.net/problem/1021
#include<stdio.h>
#define MAX 52

struct node{
	int value;
	struct node *next, *prev;
};

void set(int qsize, struct node q[]){
	for(int i=1; i<=qsize; i++){
		q[i].value = i;
		q[i].next = &q[i+1];
		q[i].prev = &q[i-1];
	}
	q[qsize].next = &q[1];
	q[1].prev = &q[qsize];
}

int main(void){
	struct node q[MAX], *ptr, *temp;
	int qsize, get, foundN, method, count, time =0;
	
	scanf("%d%d", &qsize, &get);
	set(qsize, q);
	ptr = &q[1];
	
	for(int i=0; i<get; i++){
		scanf("%d", &foundN);
		
		temp = ptr;
		for(count =0; temp->value !=foundN; count++)	temp = temp->next;
		
		if(qsize/2 >= count)	method =0;
		else method = 1, count = qsize-count;
		time += count;
		
		if(method ==0)	for(int i=0; i<count; i++)	ptr = ptr->next;
		else	for(int i=0; i<count; i++)	ptr = ptr->prev;	
		
		ptr->next->prev = ptr->prev;
		ptr->prev->next = ptr->next;
		ptr = ptr->next;
		qsize--;
	}
	
	printf("%d", time);
}
