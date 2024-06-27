#include<stdio.h>

struct student{
	char name[10];
	int age;
	int height;
};

void infor_print(struct student* a){
	printf("\n이름 : %s\n", a->name);
	printf("나이 : %d\n", a->age);
	printf("키 : %d\n", a->height);
}

int main(void){
	struct student a;
	printf("이름 입력 : ");
	scanf("%s", &a.name);
	printf("나이 입력 : ");
	scanf("%d", &a.age);
	printf("키 입력 : ");
	scanf("%d", &a.height);
	infor_print(&a);
}
