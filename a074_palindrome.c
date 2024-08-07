#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 1000

void makeSame(char* a){
	for(int i=0; i<strlen(a); i++)
		if(isupper(a[i]))
			a[i] = a[i] -'A' + 'a';
}

void flip(char* a){
	char temp;
	int len = strlen(a);
	
	if(len ==1) return;
	
	for(int i= 0; i < len/2; i++){
		temp = a[i];
		a[i] = a[len -i -1];
		a[len -i -1] = temp;
	}
} 

int compare(char* a){
	int len = strlen(a);
	
	for(int i=0; i<len/2; i++)
		if(a[i] != a[len -i -1])
			return 1;
	
	return 0;
}

int main(void){
	char num[MAX];
	
	scanf("%s", num);
	makeSame(num);
	
	//-----------
	
	printf("solution1 :\n");
	
	if(compare(num))	printf("%s is not palindrome\n", num);
	else printf("%s is palindrome\n", num);
	
	//------------
	
	printf("\nsolution2 :\n");
	
	int len = strlen(num);
	char s2[MAX/2];
	
	if(len ==1){
		printf("%s is palindrome", num);
		return 0;
	}
	
	if(len%2 ==1)	strcpy(s2, num + len/2 +1);
	else strcpy(s2, num + len/2);
	
	flip(s2);
	
	if(strncmp(num, s2, len/2))	printf("%s is not palindrome", num);
	else printf("%s is palindrome\n", num);
} 

/* 
1. 입력값 형식 일정하도록 만들기

2. 가운데를  기점으로 양끝의 원소들 각각 비교 
( for문 이용해서 양끝 원소들 각각 비교 

결국 이문제의 핵심 =>
가운데를 기점으로 양끝의 원소들이 모두 일치하는지 확인하고 싶음 */
