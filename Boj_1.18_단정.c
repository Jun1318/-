#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str[20000][51], pre[51];
int n;

int compare(const void *a, const void *b){
	char *ta = (char*)a, *tb = (char*)b;
	
	if(strlen(ta) != strlen(tb)) return strlen(ta) - strlen(tb); // 동일 길이 아니면 길이순 정렬
	return strcmp(ta, tb); // 동일 길이면 사전순 정렬
}

int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf(" %s", str[i]);
	
	qsort(str, n, sizeof(str[0]), compare);
	
	printf("%s\n", str[0]); strcpy(pre, str[0]); // 이전 문자열에 처음 단어 저장
	for(int i=1; i<n; i++) if(strcmp(pre, str[i])) printf("%s\n", str[i]), strcpy(pre, str[i]); // 이전 단어와 다를때 출력
}
