//https://www.acmicpc.net/problem/1157
#include<stdio.h>
#define size 1000000
int main(void){
	char input[size], *p=input;
	int alpha[26] = {0,}, total=0, count=0;
	scanf("%s", input);
	while(*p){
		if(*p >= 'a')	alpha[*p++ - 'a']++;
		else alpha[*p++ - 'A']++;
	}
	for(int a=0;a<26;a++){
		if(total<alpha[a]){
			input[0] = (char)(a+65);
			total = alpha[a];
			count=0;
		}
		else if(total == alpha[a])	count++;
	}
	printf("%c", (count>0)?'?':input[0]);
}
