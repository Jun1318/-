//https://www.acmicpc.net/problem/10809
#include<stdio.h>
int main(void){
	char input[100];
	int alpha[26];
	for(int a=0;a<26;a++)	alpha[a] = -1;		
	scanf("%s%*c", input);
	for(int a=0;input[a] != NULL;a++){
		int temp = (int)input[a];
		if(alpha[temp-97] == -1)	alpha[temp-97] = a; 
	}
	for(int b =0;b<26;b++)	printf("%c : %d%c", char(b+97), alpha[b], (b%10==9)?'\n':'\t');
}
