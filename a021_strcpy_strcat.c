#include<stdio.h>
#include<string.h>
#include<malloc.h>
char* copy(char*, char*);
int main(void){
	char memory[6] = "Hello";
	char memory1[6] = "World";
	printf("%s", copy(memory, memory1));
}
char* copy(char* memory, char* memory1){
	char* temp = (char*)malloc(sizeof(memory) + sizeof(memory1) +1);
	int a=0, b=0;
	while(*(memory+a) != '\0'){
		*(temp + a) = *(memory + a);
		a++;	
	}
	while(*(memory1+b) != '\0'){
		*(temp + a) = *(memory1 + b);
		b++; a++;
	}
	return temp;
}
