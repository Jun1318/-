//https://www.acmicpc.net/problem/1316
#include<stdio.h>
#include<malloc.h>
int calculate(char*);
int main(void){
	char memory[100][100];
	int input, total=0;
	scanf("%d%*c", &input);
	for(int a=0;a<input;a++)	scanf("%s%*c", memory[a]);
	for(int a=0;a<input;a++)	total += calculate(*(memory+a));
	printf("%d", total);
}

int calculate(char* memory){
	int alpha[26]={0,}, total_num = 0, appear_num=0;
	char temp;
	temp = *(memory);
	for(int a=0;;){
		if(temp != *(memory+a+1))	alpha[(int)temp - 97]++;
		temp = *(memory+ ++a);
		if(temp == NULL)	break;
	}
	for(int a=0;a<26;a++){
		if(alpha[a]>0){
			total_num++;
			appear_num += alpha[a];
		}
	}
	if(total_num == appear_num) return 1;
	else return 0;
}
