#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define maxline 1000
#define maxlen 1000
char *memory[maxline] = {NULL};

void literwrite(char *m[], int i){
	int a=0;
	while(i--)
		printf("%s\n", m[a++]);
}

void swap(char *m[], int a, int b){
	char *temp = m[a];
	m[a] = m[b];
	m[b] = temp;
}

void my_qsort(char *m[], int a, int z){
	if(a>= z)
		return;
	swap(m, a, (a+z)/2);
	int position = a;
	for(int i=position+1;i<= z; i++)
		if(strcmp(m[a], m[i])>0)
			swap(m, ++position, i);
	swap(m, a, position);
	my_qsort(m, a, position-1);
	my_qsort(m, position+1, z);
}

int main(void){
	int num=0;
	char tem_mem[maxlen];
	printf("문장 입력 - 만약 문자없이 엔터키만 누르면 종료\n");
	while(fgets(tem_mem, maxlen, stdin)!= NULL){
		if(!strcmp(tem_mem, "\n"))
			break;
		tem_mem[strlen(tem_mem)-1] = '\0';
		memory[num] = (char*)malloc(strlen(tem_mem)+1);
		if(memory[num]!=NULL)
			strcpy(memory[num], tem_mem);
			num++;
	}
	my_qsort(memory, 0, num-1);
	printf("\n정렬후\n\n");
	literwrite(memory, num);
}
