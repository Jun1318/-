//https://powerdeng.tistory.com/25
//2번쨰 문제 풀이
#include<stdio.h>
typedef struct{
	int x;
	int y;
}point;

int IsError(point* left, point* right);
int CalArea(point* left, point* right);

int main(void){
	 point leftpo, rightpo;
	 printf("좌 하단의 좌표 입력 : ");
	 scanf("%d %d", &leftpo.x, &leftpo.y);
	 while(1){
	 	printf("우 상단의 좌표 입력 :");
	 	scanf("%d %d", &rightpo.x, &rightpo.y);
	 	if(!IsError(&leftpo, &rightpo))	break;
	 }
	 printf("정사각형의 넓이는 %d입니다.", CalArea(&leftpo, &rightpo));
}

int IsError(point* left, point* right){
	int error_x=0;
	int error_y=0;
	if(left->x >= right->x)	error_x++;
	if(left->y >= right->y)	error_y++;
	if(error_x + error_y > 0){
		if(error_x + error_y == 2)	printf("우 상단의 x 좌표와, y 좌표가 좌 하단의 x,y 좌표보다 작거나 같습니다\n\n");
		else{
			if(error_x == 1)	printf("우상단의 x좌표가 좌하단의 x좌표보다 작거나 같습니다\n\n");
			if(error_y == 1)	printf("우상단의 y좌표가 좌하단의 y좌표보다 작거나 같습니다\n\n");
		}
		return 1;
	}
	return 0;
}

int CalArea(point* left, point* right){
	int Area;
	Area = (right->x - left->x) * (right->y - left->y);
	return Area;
}
