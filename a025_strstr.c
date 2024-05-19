#include<stdio.h>
#include<string.h>

char memory[] = "abababbabcab";
char sub[] = "abc";

char* my_strstr(char*, char*);
int main(void){
	printf("strstr() : %s\n", strstr(memory, sub));
	printf("my_strstr() : %s\n", my_strstr(memory, sub));
}

char* my_strstr(char* memory, char* sub){
	int size1 = strlen(memory), size2 = strlen(sub);
	while(size1>= size2){
		char* str1 = memory;
		char* str2 = sub;
		while(*str1 == *str2 && *str2 != NULL){
			str1++;
			str2++;
		}
		if(*str2 == NULL)	return memory;
		memory++;
		size1--;
	}
	return NULL;
}
