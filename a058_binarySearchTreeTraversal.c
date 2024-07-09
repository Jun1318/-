#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int key;
	struct node *left, *right;
}treenode;

treenode* makeNode(int value){
	treenode *temp = (treenode*)malloc(sizeof(treenode));
	
	temp->key = value;
	temp->left = temp->right = NULL;
	return temp;
}

treenode* insert(treenode *node, int data){
	if(node == NULL)
		return makeNode(data);
	if(data<node->key)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);

	return node;
}

treenode* miniNode(treenode* node){
	if(node == NULL)
		return node;
	while(node->left)
		node = node->left;
		
	return node;
}

treenode* deleteNode(treenode* node, int data){
	if(node == NULL)
		return node;
	if(data<node->key)
		node->left = deleteNode(node->left, data);
	else if(data>node->key)
		node->right = deleteNode(node->right, data);
	else{
		if(node->left == NULL){
			treenode* temp = node->right;
			free(node);
			return temp;
		}else if(node->right == NULL){
			treenode* temp = node->left;
			free(node);
			return temp;
		}
		
		treenode* temp = miniNode(node->right);
		node->key = temp->key;
		node->right = deleteNode(node->right, temp->key);
	}
	return node;
}

void inorder(treenode* node){
	if(node != NULL){
		inorder(node->left);
		printf("%d -> ", node->key);
		inorder(node->right);
	}
}

void preorder(treenode* node){
	if(node != NULL){
		printf("%d -> ", node->key);
		preorder(node->left);
		preorder(node->right);	
	}
}

void postorder(treenode* node){
	if(node != NULL){
		postorder(node->left);
		postorder(node->right);
		printf("%d -> ", node->key);
	}
}

void traverse(treenode* root){
	printf("\ninorder :\n");
	inorder(root);
	printf("\npreorder :\n");
	preorder(root);
	printf("\npostorder :\n");
	postorder(root);
}

int main(void){
	treenode* root = NULL;
	int data[] = {10, 8, 6, 9, 7, 15, 12, 14};
	int del;
	
	for(int i=0;i<10;i++)
		root = insert(root, data[i]);
		
	traverse(root);
	
	while(1){
		printf("\n\nenter node to delete(-1 to quit): ");
		scanf("%d", &del);
		if(del == -1)
			break;
		root = deleteNode(root, del);
		traverse(root);
	}
}
