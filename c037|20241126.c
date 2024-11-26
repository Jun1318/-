#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int t, value, place, zeroN;
	struct Node *next;
}Node;

Node *head, **map;
int x, y;

void input(int n, int v){
	map[n] = (Node*)malloc(sizeof(Node));
	
	map[n]->next = head->next, head->next = map[n];
	map[n]->t = 0, map[n]->value = v, map[n]->place = n;
}

void zeroCount(int p){
	int total =0;
	
	if(p/y && map[p-y] != NULL)	total++;
	if(p/y != x-1 && map[p+y] != NULL)	total++;
	if(p%y && map[p-1] != NULL)	total++;
	if(p%y != y-1 && map[p+1] != NULL)	total++;
	
	map[p]->zeroN = 4 - total;
}

void cal(int p){
	map[p]->t++;
	if(map[p]->value <= map[p]->zeroN) map[p]->value = 0;
	else map[p]->value -= map[p]->zeroN;
	
	if(p/y && map[p-y] != NULL && map[p-y]->t != map[p]->t)	cal(p-y);
	if(p/y != x-1 && map[p+y] != NULL && map[p+y]->t != map[p]->t)	cal(p+y);
	if(p%y && map[p-1] != NULL && map[p-1]->t != map[p]->t)	cal(p-1);
	if(p%y != y-1 && map[p+1] != NULL && map[p+1]->t != map[p]->t)	cal(p+1);
}

void renewZeroN(Node *p, Node *pp){
	if(p == NULL)	return;
	
	if(!p->value){
		int i = p->place;

		if(p->place/y && map[p->place-y] != NULL)	map[p->place-y]->zeroN++;
		if(p->place/y != x-1 && map[p->place+y] != NULL)	map[p->place+y]->zeroN++;
		if(p->place%y && map[p->place-1] != NULL)	map[p->place-1]->zeroN++;
		if(p->place%y != y-1 && map[p->place+1] != NULL)	map[p->place+1]->zeroN++;
		
		pp->next = p->next, free(p), map[i] = NULL;
		
		return renewZeroN(pp->next, pp);
	}
	
	return renewZeroN(p->next, p);
}

int main(void){
	int time =0, temp, total =0;
	head = (Node*)malloc(sizeof(Node)), head->next = NULL;
	
	scanf("%d%d", &x, &y);
	map = (Node**)malloc(sizeof(Node) * (x*y));
	for(int i=0; i<x*y; i++)	map[i] = NULL;
	for(int i=0; i<x*y; i++){
		scanf("%d", &temp);	
		if(temp)	input(i, temp);
	}
	for(Node *p = head->next; p; p = p->next)	zeroCount(p->place);
	
	while(head->next){
		time++, total =0;
		for(Node *p = head->next; p; p = p->next)	if(p->t != time)	total++, cal(p->place);
		renewZeroN(head->next, head);
		if(total != 1)	break;
	}
	
	if(total ==1)	printf("0");
	else printf("%d", time -1);
}
