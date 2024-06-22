#include<stdio.h>
#define INT 0
#define FLOAT 1
#define LEN 3

void add(void memory[], void *total, int len, int type){
	switch(type){
		case INT:
			while(len)
				*(int*)total += ((int*)memory)[--len];
			break;
		case FLOAT:
			while(len)
				*(float*)total += ((float*)memory)[--len];
	}
}

int main(void){
	int i_m[LEN] = {1,2,3}, i_total=0;
	float f_m[LEN] = {1.0, 2.0, 3.0}, f_total=0.0;
	add(i_m, &i_total, LEN, INT);
	add(f_m, &f_total, LEN, FLOAT);
	printf("정수 배열 원소 총합 : %d\n", i_total);
	printf("실수 배열 원소 총합 : %.1f\n", f_total);
}
