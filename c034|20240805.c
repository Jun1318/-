//보이어 무어 알고리즘 - bad character 버전
#include<stdio.h>
#include<string.h>
#define MAX 256

int checkAlpha(char c, char* a, int len){
	for(int i=0; i<len; i++)
		if(a[i] == c)
			return 0;
	
	return 1;
}

int boyer(char* txt, char* pat){
	int len_T = strlen(txt);
	int len_P = strlen(pat);
	int preP = len_P-1;
	
	while(preP < len_T){
		int minus =0;
		
		while(minus < len_P && txt[preP -minus] == pat[len_P -1 -minus])
			minus++;
		
		if(minus == len_P)
			return preP -len_P +1;
		
		if(checkAlpha(txt[preP -minus], pat, len_P))
			preP += len_P -minus; // 왜 minus 안빼는거지? 
		
		else{
			for(int i=0;i<len_P; i++)
				if(txt[preP-minus] == pat[i]){
					preP = preP -minus + len_P - i -1;
					break;
				}
		}
		
	}
	
	return -1;
}

int main(void){
	char txt[MAX];
	char pat[MAX];
	
	printf("txt[] : ");
	scanf("%s", txt);
	printf("pat[] : ");
	scanf("%s", pat);
	
	int result = boyer(txt, pat);
	if(result == -1)	printf("\ncannot found pattern\n");
	else printf("pattern start position : %d", result+1);
}
