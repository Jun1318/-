#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define trials 1000000
int main(){
	int memory[12] = {0,};
	int temp=0;
	srand((unsigned)time(NULL));
	for(int a=0;a<trials;a++){
		temp = rand()%6+1;
		temp += rand()%6+1;
		memory[temp-1] += 1;
	}
	for(int a=1;a<12;a++)
		printf("%d의 확률 = %5.2f%%, 나온 횟수 = %d\n", a+1, (double)memory[a]/trials*100, memory[a]);
}
