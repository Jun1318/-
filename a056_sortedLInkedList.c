#include<stdio.h>
#include<stdlib.h>

struct node{
	int value;
	struct node* next;
};

struct node *head = NULL;

void insert_list(void){
	struct node *ptr, *temp;
	
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL){
		printf("out of memory!\n");
		exit(0);
	}
	
	printf("enter data :");
	scanf("%d", &temp->value);
	temp->next = NULL;
	
	if(head == NULL){
		head = temp;
	}else{
		if(head->value > temp->value){
			temp->next = head;
			head = temp;
		}else{
			for(ptr=head;ptr->next;ptr=ptr->next){
				if(ptr->next->value>temp->value){
					temp->next = ptr->next;
					ptr->next = temp;
					return;
				}
			}
			ptr->next = temp;
		}
	}
}

void delete_list(void){
	int data;
	struct node *ptr=head, *temp;
	
	if(head == NULL){
		printf("empty list, return without deleting!\n");
		return;
	}
	
	printf("enter data to delete :");
	scanf("%d", &data);
	
	if(data == head->value){
		head = head->next;
		free(ptr);
		return;
	}else{
		for(;ptr->next;ptr=ptr->next){
			if(ptr->next->value == data){
				printf("%d deleted!\n", ptr->next->value);
				temp = ptr->next;
				ptr->next = ptr->next->next;
				free(temp);
				return;
			}
		}
	}
	printf("data not found!\n");
}

void display(void){
	struct node *ptr = head;
	
	if(ptr == NULL){
		printf("list is empty!\n");
		return;
	}else{
		printf("list :");
		while(ptr){
			printf("%d ->\t", ptr->value);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

int main(void){
	int choice;
	
	while(1){
		printf("\n======Menu======\n");
		printf("1.insert\n");
		printf("2.delete\n");
		printf("3.display\n");
		printf("0.exit\n");
		printf("-----------------\n");
		printf("enter your choice :");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				insert_list();
				display();
				break;
			case 2:
				delete_list();
				display();
				break;
			case 3:
				display();
				break;
			case 0:
				exit(0);
		}
	}
}
