#include<stdio.h>
enum size {Short, Tall, Grande, Venti};
char sizename[][7] = {"Short", "Tall", "Grande", "Venti"};
int priceAmericano[] = {3800, 4100, 4600, 5100};
int priceCappucino[] = {4800, 5100, 5600, 6100};
int main(){
	printf("아메리카노 커피 사이즈 별 가격\n");
	for(int a=Short;a<=Venti;a++)	printf("%s : %d\n", sizename[a], priceAmericano[a]);
	printf("\n카푸치노 커피 사이즈 별 가격\n");
	for(int a=Short;a<=Venti;a++)	printf("%s : %d\n", sizename[a], priceCappucino[a]);
}
