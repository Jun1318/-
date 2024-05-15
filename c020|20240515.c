//https://www.acmicpc.net/problem/1316
#include<stdio.h>
int calculate(int*);
int main(void){
	int memory[26]={0,}, input, count=0, word;
	scanf("%d", &input);
	char c_memory[input][100];
	for(int a=0;a<input;a++)	scanf("%s%*c", &c_memory[a]);
	for(int a=0;count<input;){
		word = (int)c_memory[count][a];
		if(c_memory[count][a] != c_memory[count][++a]) memory[word-97]++; // 다음 소문자와 현재 소문자와 다르면 현재 소문자 해당 배열 1증가 
		if(c_memory[count][a] == NULL){
			count++;
			printf("%d\n", calculate(memory));
			a = 0;
		}
	}
}

int calculate(int* memory){
	int total = 0;
	for(int a=0;a<26;a++){
		if(*(memory+a) > 0)	total++;
		*(memory+a) = 0;
	}
	return total;
}
