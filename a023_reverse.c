#include<stdio.h>
#include<string.h>
char* mirror(char*);
int main(void){
	char memory[15] = "Hello, World!\0";
	printf("전환된 문자열 : %s", mirror(memory));
}

char* mirror(char* memory){
	char* memory1 = memory + strlen(memory) -1;
	for(char* memory2 = memory; memory2<memory1; memory2++, memory1--){
		char temp = *memory2;
		*memory2 = *memory1;
		*memory1 = temp;
	}
	return memory;
}
