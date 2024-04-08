#include<stdio.h>
#include<string.h>
int main(void){
	int a, e=1, f=0;
	char ox[80]; // 입력받을 배열 선언 
	
	printf("입력할 개수 적기: ");
	scanf("%d", &a); // 입력할 개수  입력받기 
	
	int g[a]; // 계산한거 입력할 배열 선언 
	
	for(int c=0;c<a;c++){ //  입력 개수만큼 반복 
		printf("입력하기:");
		scanf("%s", ox);
		for(int d=0;d<strlen(ox);d++){
			if(ox[d] =='x' || ox[d]=='X')
				e = 1;
			else{
				f += e;
				++e;
			}
		}
		e = 1;
		g[c] = f;
		f = 0;
	}
	
	for(int h=0;h<a;h++)
		printf("%d\n", g[h]);
	
	return 0;
}
