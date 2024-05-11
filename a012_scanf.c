#include<stdio.h>
int main(void){
	int a, b,c;
	char s[100];
	
	int x = scanf("%d%c%d", &a, &b, &c);
	printf("%d\n", x);
	getchar();
	
	printf("이거는 숫자만 인식하는 scanf\n");
	scanf("%[0-9]s", &s);
	printf("%s\n", s);
}
