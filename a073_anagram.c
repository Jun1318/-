#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<ctype.h>
#define MAX 100

void toLower(char[]);
void sortArray(char[]);
int anagram1(char*, char*);
int anagram2(char*, char*);

int main(void){
	char word1[MAX], word2[MAX];
	
	printf("enter word1 : ");
	scanf("%s", word1);
	printf("enter word2 : ");
	scanf("%s", word2);
	
	if(strlen(word1) != strlen(word2))
		printf("두 문자열의 길이가 달라 애너그램이 아닙니다.\n");
	else{
		if(anagram1(word1, word2))	printf("%s와 %s는 애너그램입니다.\n", word1, word2);
		else	printf("%s와 %s는 애너그램이 아닙니다.\n");
		
		if(anagram2(word1, word2))	printf("%s와 %s는 애너그램이 아닙니다.\n", word1, word2);
		else	printf("%s와 %s는 애너그램입니다.\n", word1, word2);
	}
}

int anagram1(char* word1, char* word2){
	char* s1 = (char*)malloc(strlen(word1)+1);
	char* s2 = (char*)malloc(strlen(word2)+1);
	
	strcpy(s1, word1);
	strcpy(s2, word2);
	
	toLower(s1);
	toLower(s2);
	
	sortArray(s1);
	sortArray(s2);
	
	if(!strcmp(s1, s2))	return 1;
	return 0;
}

int anagram2(char* word1, char* word2){
	int alpha1[26] ={0}, alpha2[26] ={0};
	char* s1 = (char*)malloc(strlen(word1));
	char* s2 = (char*)malloc(strlen(word2));
	
	strcpy(s1, word1);
	strcpy(s2, word2);
	
	toLower(s1);
	toLower(s2);
	
	while(*s1 != '\0'){
		alpha1[*s1 - 'a']++;
		alpha2[*s2 - 'a']++;
		s1++;
		s2++;
	}
	
	for(int i=0; i<26; i++)
		if(alpha1[i] != alpha2[i])
			return 1;
	
	return 0;
}

void toLower(char a[]){
	for(int i=0; i<strlen(a)-1; i++)
		if(isupper(a[i]))
			a[i] = a[i] - 'A' + 'a';
}

void sortArray(char a[]){
	for(int i=0; i<strlen(a)-1; i++)
		for(int j= i+1; j<strlen(a); j++)
			if(a[i] > a[j]){
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}
