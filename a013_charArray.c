#include<stdio.h>
int main(void){
	char s[10] = {'a','b','c','d','e'};
	char t[] = {'a','b','c','d','e'};
	char u[] = "abcde";
	char v[] = "안녕하세요";
	
	printf("문자열 s의 크기 : %d\n", sizeof(s));
	printf("문자열 t의 크기 : %d\n", sizeof(t));
	printf("문자열 u의 크기 : %d\n", sizeof(u));
	printf("문자열 v의 크기 : %d\n", sizeof(v));
}
