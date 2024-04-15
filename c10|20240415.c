//https://www.acmicpc.net/problem/1152
#include<stdio.h>
#include<string.h>

#define NONE " "

int main(void){
	char memory[1000001]; // 문자열 입력받을 배열 
	gets(memory);
	int wordtotal = 0; // 총 단어 갯수 
	int cal = 0;
	char *pointer = memory;
	
	if(strlen(memory) > 1000000)
		return 0;
		
	while(1){
		if(*(pointer+cal) != ' '); // 만약 현재 포인터가 가르키는 문자가 공백이 아니라면 단어 개수 세기 시작 
			break;
		cal++;
	}
	
	while(1){
		if(*(pointer+cal) == ' ' && *(pointer +cal +1) != ' ')
			wordtotal++;
		if(cal == strlen(memory))
			break;
		cal++;
	}
	
	printf("%d", wordtotal+1);
}
