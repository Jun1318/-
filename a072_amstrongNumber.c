#include<stdio.h>
#include<math.h>

int checkAmstrong(int origin){
	int totalLen=0, sum=0;
	int temp = origin;
	
	while(temp != 0){
		temp /= 10;
		totalLen++;
	}
	
	temp = origin;
	
	while(temp !=0){
		sum += pow(temp%10, totalLen);
		temp /= 10;
	}
	
	if(sum == origin)	return 1;
	return 0;
}

int main(void){
	int from, to;
	
	printf("암스트롱 수를 찾는 범위를 입력하세요(from to) : ");
	scanf("%d %d", &from, &to);
	
	for(int i=from; i<=to; i++)
		if(checkAmstrong(i))
			printf("%8d\n", i);
	printf("\n끝남");
}
