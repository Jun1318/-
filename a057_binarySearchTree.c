#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int key;
	struct node *left, *right;
};

struct node* makenode(int data){
	struct node *ptr = (struct node*)malloc(sizeof(node));
	
	ptr->key = data;
	ptr->left = ptr->right = NULL;
	return ptr;
}

struct node* insert(struct node *node, int data){
	if(node == NULL)
		return makenode(data);
	if(data<node->key)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	return node;
}

struct node* miniNode(struct node* node){
	struct node* cur = node;
	
	if(cur == NULL)
		return NULL;
	while(cur->left != NULL)
		cur = cur->left;
	return cur;
}

struct node* deleteNode(struct node* node, int data){
	if(node == NULL)
		return node;
	if(data<node->key)
		node->left = deleteNode(node->left, data);
	else if(data > node->key)
		node->right = deleteNode(node->right, data);
	else{
		if(node->left == NULL){
			struct node* temp = node->right;
			free(node);
			return temp;
		}else if(node->right == NULL){
			struct node* temp = node->left;
			free(node);
			return temp;
		}
		
		struct node* temp = miniNode(node->right);
		node->key = temp->key;
		node->right = deleteNode(node->right, temp->key);
	}
	return node;
}

void inorder(struct node* node){
	if(node != NULL){
		inorder(node->left);
		printf("%d-> ", node->key);
		inorder(node->right);
	}
}

int main(void){
	struct node* root = NULL;
	int data[] = {10, 8, 6, 9, 7, 15, 12, 14};
	int del;
	
	for(int i=0;i<9;i++)
		root = insert(root, data[i]);
		
	inorder(root);
	
	while(1){
		printf("\nenter node to delete(-1 to quit): ");
		scanf("%d", &del);
		if(del == -1)
			break;
		root = deleteNode(root, del);
		inorder(root); 
	}
}
