#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int value;
	struct node *next;
};

struct node *head = NULL;

void append();
void insert();
void insert_pos();
void display();
void delete_begin();
void delete_end();
void delete_pos();

void append(void){
	struct node *ptr, *temp;
	
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
	struct node *temp = (struct node*)malloc(sizeof(struct node));
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
		temp->next = head;
		head = temp;
	}
}

void insert_pos(void){
	struct node *temp, *ptr;
	int position;
	
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL){
		printf("out of memory!\n");
		exit(0);
	}
	
	printf("\nenter data :");
	scanf("%d", &temp->value);
	printf("enter position to insert :");
	scanf("%d", &position);
	temp->next = NULL;
	
	if(position == 0){
		temp->next = head;
		head = temp;
	}else{
		ptr = head;
		for(int i=0;i<position-1;i++){
			ptr= ptr->next;
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
		printf("list : ");
		while(ptr != NULL){
			printf("%d ->\t", ptr->value);
			ptr = ptr->next;
		}
	}
}

void delete_begin(void){
	struct node *ptr = head;
	
	if(ptr == NULL){
		printf("list is empty!\n");
		return;
	}else{
		head = head->next;
		printf("the deleted node is %d", ptr->value);
		free(ptr);
	}
}

void delete_end(void){
	struct node *temp = NULL, *ptr = NULL;
	
	if(head ==NULL){
		printf("listis empty!\n");
		return;
	}else{
		ptr = head;
		while(ptr->next != NULL){
			temp = ptr;
			ptr = ptr->next;
		}
		temp->next = NULL;
		printf("the deleted node is %d", ptr->value);
		free(ptr);
	}
}

void delete_pos(void){
	struct node *temp = NULL, *ptr = NULL;
	int position;
	
	if(head == NULL){
		printf("list is empty!\n");
		return;
	}
	
	printf("enter the position to delete :");
	scanf("%d", &position);
	if(position == 0){
		ptr = head;
		head = head->next;
		printf("the deleted node is %d", ptr->value);
		free(ptr);
	}else{
		ptr = head;
		for(int i=0;i<position;i++){
			temp = ptr;
			ptr = ptr->next;
			if(ptr == NULL){
				printf("position not found\n");
				return;
			}
		}
		temp->next = ptr->next;
		printf("the deleted node is %d", ptr->value);
		free(ptr);
	}
}

int main(void){
	int num;
	while(1){
		printf("\n\n========MENU========\n");
		printf("1.append\n");
		printf("2.insert\n");
		printf("3.insert at position\n");
		printf("4.display\n");
		printf("5.delete beginning\n");
		printf("6.delete end\n");
		printf("7.delete position\n");
		printf("0.exit\n");
		printf("---------------------\n");
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
			case 5:
				delete_begin();
				break;
			case 6:
				delete_end();
				break;
			case 7:
				delete_pos();
				break;
			case 0:
				exit(0);
		}
	}
}
