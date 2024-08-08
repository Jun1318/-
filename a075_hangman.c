#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

#define MAX_COUNT 200
#define BUFFER_SIZE 20

char words[MAX_COUNT][BUFFER_SIZE];
char inputs[BUFFER_SIZE];

int index;
int life =10;
int opens =0;

int readDictionary(void);
void printHead(void);
void printWords(char ch[]);
int isInInputs(char c);
void addInInputs(char c);
void printAlphabet(void);

int main(void){
	char c;
	int count = readDictionary();
	
	printf("%d words read...", count);
	Sleep(1000);
	
	srand(time(0));
	index = rand() %count;
	do{
		printHead();
		printf("알파벳을 입력하세요 : ");
		c = getche();
		addInInputs(c);
	}while(opens != strlen(words[index]) && life !=0);
	
	printHead();
	if(life ==0)	printf("\n실패! - 정답 : %s", words[index]);
	else	printf("\n성공!!");
}

void printHead(void){
	system("cls");
	printf("==HangMan!!==\n");
	printf("\nLife = %d\n", life);
	printf("시도한 알파벳 : ");
	printAlphabet();
	printWords(inputs);
}

void printAlphabet(){
	for(int i=0; inputs[i] !='\0'; i++)
		printf("%c", inputs[i]);
	printf("\n");
}

int readDictionary(void){
	FILE* fp;
	char line[20];
	int cnt =0;
	
	fp = fopen("왕가므자.txt", "r");
	if(fp == NULL){
		printf("Error reading rile");
		exit(0);
	}
	
	while(fgets(line, BUFFER_SIZE, fp) !=NULL)
		strcpy(words[cnt++], line);
	fclose(fp);
	return cnt;
}

void printWords(char input[]){
	printf("┎ ");
	for(int i=0; i <strlen(words[index]) -1; i++)
		printf("━━");
	printf(" ┒\n│");
	for(int i =0; i <strlen(words[index]); i++)
		if(isInInputs(words[index][i]))	printf("%c ", words[index][i]);
		else	printf("_ ");
	
	printf("│\n┖ ");
	for(int i=0; i <strlen(words[index]) -1; i++)	printf("━━");
	printf(" ┚\n");
}

int isInInputs(char c){
	for(int i=0; inputs[i] !='\0'; i++)
		if(inputs[i] ==c)
			return 1;
	return 0;
}

void addInInputs(char c){
	int i=0;
	for(; inputs[i] !='\0'; i++)
		if(inputs[i] ==c){
			printf("\n이미 선택한 문자입니다.");
			Sleep(1000);
			return;
		}
		
	inputs[i] =c;
	life--;
	
	for(i =0; words[index][i] != '\0'; i++)
		if(words[index][i] ==c)
			opens++;
}
