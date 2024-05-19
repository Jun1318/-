#include<stdio.h>
#include<math.h>
int calculate(long long);
int main(void){
	long long value_2;
	scanf("%11d%*c", &value_2);
	printf("%11d 변환값 : %d", value_2, calculate(value_2));
}

int calculate(long long i){
	int total =0, count = 0;
	while(i){
		total += i%10*pow(2, count);
		count++;
		i /=10;
	}
	return total;
}
