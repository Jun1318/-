// https://www.acmicpc.net/problem/1009
#include<stdio.h>
int calculate(int, int);
int main(void){
	int num, g, h;
	
	printf("입력할 데이터 개수 입력 :");
	scanf("%d", &num);
	
	int c[num]; // 제곱 나머지 넣을 배열 만듬 
	
	for(int a=0;a<num;a++){
		printf("몫과 제곱 수 입력:");
		scanf("%d %d", &g, &h);
		c[a] = calculate(g, h) % 10;
	}
	
	
	for(int j = 0;j<num;j++){
		if(g <= 0)
			printf("몫에는 자연수를 입력해 주세요");
		else if(c[j] == 0)
			printf("10번 컴퓨터가 처리함");
		else
			printf("%d번 컴퓨터가 처리함", c[j]);
	}
	
	return 0;
}

int calculate(int g, int h){
	int result = 1;
	for(int r =0;r<h;r++){
		result *= g;
	}
	return result;
}
	
