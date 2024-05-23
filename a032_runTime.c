#include <stdio.h>
#include<string.h>
#include<time.h>
int main(void) {
	double start, end;
	start = (double)clock()/CLOCKS_PER_SEC;
	
	int sum = 0;
	for(int a=0;a<1000000;a++)	sum++;
	
	end = (double)clock()/CLOCKS_PER_SEC;
	printf("걸린 시간 : %f", end-start);
}
