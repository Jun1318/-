#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void append();
void insert();
void insert_pos();
void display();

struct node{
	int value;
	struct node *next;
};

struct node *head = NULL;

void append(void){
	struct node *temp, *ptr;
	
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL){
		printf("out of memory!\n");
		exit(0);
	}
	
	printf("\nenter data :");
	scanf("%d", &temp->value);
	temp->next = NULL;
	
	if(head == NULL){
		head = temp;
	}else{
		ptr = head;
		while(ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
	}
}

void insert(void){
	struct node *temp, *ptr;
	
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp ==NULL){
		printf("out of memory!\n");
		exit(0);
	}
	
	printf("\nenter data :");
	scanf("%d", &temp->value);
	temp->next = NULL;
	
	if(head == NULL){
		head = temp;
	}else{
		temp->next = head;
		head = temp;
	}
}

void insert_pos(void){
	struct node *temp, *ptr;
	int position;
	
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL){
		printf("out of data\n");
		exit(0);
	}
	
	printf("\nenter position to insert :");
	scanf("%d", &position);
	printf("enter the data :");
	scanf("%d", &temp->value);
	temp->next = NULL;
	
	if(position == 0){
		temp->next = head;
		head = temp;
	}else{
		ptr = head;
		for(int i=0;i<position-1;i++){
			ptr = ptr->next;
			if(ptr == NULL){
				printf("cannot insert at %d\n", position);
				return;
			}
		}
		temp->next = ptr->next;
		ptr->next = temp;
	}
}

void display(void){
	struct node *ptr = head;
	
	if(ptr == NULL){
		printf("list is empty!\n");
		return;
	}else{
		printf("list :");
		while(ptr != NULL){
			printf("%d->\t", ptr->value);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

int main(void){
	int num;
	while(1){
		printf("\n========MENU========\n");
		printf("1.append\n");
		printf("2.insert\n");
		printf("3.insert at position\n");
		printf("4.display\n");
		printf("0.exit");
		printf("-------------------------\n");
		printf("enter your choice :");
		scanf("%d", &num);
	
		switch(num){
			case 1:
				append();
				break;
			case 2:
				insert();
				break;
			case 3:
				insert_pos();
				break;
			case 4:
				display();
				break;
			case 0:
				exit(0);
		}
	}
}
