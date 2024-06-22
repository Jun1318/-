#include<stdio.h>
#define INT 0
#define FLOAT 1
#define DOUBLE 2

void add(void *a, void *b, void *result, int type){
	switch(type){
		case 0:
			*(int*)result = *(int*)a + *(int*)b;
			break;
		case 1:
			*(float*)result = *(float*)a + *(float*)b;
			break;
		case 2:
			*(double*)result = *(double*)a + *(double*)b;
			break;
	}
}
int main(void){
	int ia = 1, ib = 2, ir;
	float fa = 2.0, fb = 1.1, fr;
	double da = 3.2, db = 2.2, dr;
	add(&ia, &ib, &ir, INT);
	add(&fa, &fb, &fr, FLOAT);
	add(&da, &db, &dr, DOUBLE);
	printf("정수형 계산 %d + %d : %d\n", ia, ib, ir);
	printf("실수형 계산 %2.1f + %2.1f : %2.1f\n", fa, fb, fr);
	printf("더블형 계산 %2.1f + %2.1f : %2.1f\n", da, db, dr);
}
