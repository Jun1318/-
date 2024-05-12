#include<stdio.h>
#include<string.h>
int main(void){
	char name[][20] = {{'s', 's', 'j'}, {'k','j','h'},{'j','y','h'}};
	strcpy(name[0], "손상준");
	strcpy(name[1], "김주혁");
	strcpy(name[2], "진연훈");
	for(int a=0;a<3;a++)	printf("%s\n", name[a]);
}
