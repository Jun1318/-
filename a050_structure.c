#include<stdio.h>
#include<math.h>

struct point{
	int x;
	int y;
};

double distance(struct point p1, struct point p2){
	return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y - p2.y, 2));
}

double area(struct point ptr1, struct point ptr2){
	return (ptr2.x-ptr1.x)*(ptr1.y-ptr2.y);
}

int main(void){
	struct point p1 = {10, 20};
	struct point p2 = {15, 5};
	
	printf("거리 계산 : %.2f\n", distance(p1, p2));
	printf("넓이 계산 : %d * %d = %.2f", p2.x-p1.x, p1.y-p2.y, area(p1, p2));
}
