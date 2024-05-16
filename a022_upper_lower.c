#include<stdio.h>
void to_upper(char*);
void to_lower(char*);
int main(void){
	char memory[15] = "hello, world";
	to_lower(memory);
	printf("%s\n", memory);
	to_upper(memory);
	printf("%s\n", memory);
}

void to_lower(char* memory){
	while(*memory){
		if(*memory>= 'a' && *memory<= 'z')	*memory = *memory - 'a' + 'A';
		memory++;
	}
}

void to_upper(char* memory){
	while(*memory){
		if(*memory>= 'A' && *memory <= 'Z')	*memory = *memory - 'A' + 'a';
		memory++;
	}
}
