#include<stdio.h>
int main(void){
	char memory1[5] = "abcd";
	char* p_memory1 = "abcd";
	for(int a=0;a<4;a++)	printf("a : %c\n", memory1[a]);
	for(int a=0;a<4;a++)	printf("pa : %c\n", *(p_memory1+a));
	char* p_memory2[] = {"손상준", "김주혁", "진연훈"};
	for(int a=0;a<3;a++)	printf("이름 : %s\t", p_memory2[a]);
}
