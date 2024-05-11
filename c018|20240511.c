#include<stdio.h>
struct triangle{
	int x;
	int y;
	int z;
};
int classification(int, int, int);
int main(void){
	struct triangle list;
	while(1){
		printf("삼각형 3변의 길이를 입력하세요 : ");
		scanf("%d%*c%d%*c%d[^\n]", &list.x, &list.y, &list.z);
		switch(classification(list.x, list.y, list.z)){
			case 0: printf("입력하신 삼각형은 그냥 삼각형 입니다."); return 0;
			case 2: printf("입력하신 삼각형은 이등변 삼각형입니다."); return 0;
			case 3: printf("입력하신 삼각형은 정삼각형입니다."); return 0;
			default: printf("입력하신 변들로는 삼각형이 만들어지지 않습니다.\n");
		}
	}
}

int classification(int x, int y, int z){
	int max;
	if((x>=y)? 1 : 0)	(x>=z)? max = x-y-z : max = z-x-y;
	else (y>=z)? max = y-x-z : max = z-x-y;
	
	if(max > 0)	return 1;
	if(x == y && x == z)	return 3;
	if(x == y || x == z || y == z) return 2;
	else return 0;
}
