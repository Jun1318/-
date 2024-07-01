#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define max 1000

typedef struct point{
	int x;
	int y;
}point;

typedef struct pointpair{
	double dist;
	point p2;
	point p1;
}pointpair;

point p[max];

double dist(point p1, point p2){
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

pointpair makepair(point p1, point p2){
	pointpair pp;
	
	pp.dist = dist(p1, p2);
	pp.p1 = p1;
	pp.p2 = p2;
	return pp;
}

pointpair closest(void){
	pointpair MIN;
	double min = max*max, temp;
	
	for(int a=0;a<100;a++){
		for(int b=0;b<100;b++){
			if(a==b)
				continue;
			if((temp = dist(p[a], p[b]))<min){
				min = temp;
				MIN = makepair(p[a], p[b]);
			}
		}
	}
	return MIN;
}

int main(void){
	pointpair pp;
	srand((unsigned)time(NULL));
	
	for(int i=0;i<max;i++){
		p[i].x = rand()%max;
		p[i].y = rand()%max;
	}
	
	pp = closest();
	printf("가장 짧은 선 - %d,%d %d,%d --> %.2f", pp.p1.x, pp.p1.y, pp.p2.x, pp.p2.y, pp.dist);
}
