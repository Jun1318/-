#include<stdio.h>
struct student{
	char name[10];
	char address[30];
};
int main(void){
	const int n = 2;
	struct student list[n];
	for(int a=0;a<n;a++){
		printf("학생의 이름을 입력하세요 : ");
		scanf("%s", list[a].name);
		getchar();
		printf("학생의 주소를 입력하세요 : ");
		scanf("%[^\n]s", list[a].address);
		fflush(stdin);
	}
	for(int a=0;a<n;a++)	printf("학생 이름 :%s, 학생 주소 : %s\n", list[a].name, list[a].address);
}
