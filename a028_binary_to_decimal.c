#include<stdio.h>
#include<math.h>
long long calculate(int);
int main(void){
	int input;
	scanf("%d", &input);
	printf("입력한수 %d 2진수 변환 : %11d", input, calculate(input));
}
char* calculate(int i){
	long long total_2 = 0;
	int temp, mask = 0x01;
	for(int a=0;a<10;a++){
		temp = mask & i;
		total_2 += temp * pow(10, a);
		i = i>>1;
	}
	return total_2;
}
