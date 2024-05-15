#include<stdio.h>
#include<string.h>
int count(char*);
int count2(char*);
int main(void){
	char memory[15] = "Hello, world";
	printf("문자열 길이 : %d\n", count(memory));
	printf("문자열 보낸 곳부터 끝까지의 길이 : %d", count2(memory+2));
}
int count(char* memory){
	int total = 0;
	for(int a=0;*(memory+a) != '\0'; a++)	total++;
	return total;
}

int count2(char* memory){
	char* p = memory;
	while(*p != '\0')	p++;
	return p - memory;
}
