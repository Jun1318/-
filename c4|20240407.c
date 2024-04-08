//문제 - https://www.acmicpc.net/problem/1837
#include<stdio.h>
#include<math.h>
int main(void){
	int a, b, c=0;
	
	while(1){
	scanf("%d %d", &a, &b);
	if(a<4 || a>pow(10,100))
		printf("소수의 곱은 4이상, 10^100이하로 입력하세요\n");
	else if(b<2 || b>pow(10, 6))
		printf("암호는 2이상, 10^6이하로 입력해 주세요\n");
	else
		break;
	}
	
	for(int d=2;d<a;d++){
		if(a%d == 0 && d<b){
			printf("BAD %d", d);
			return 0;
		}
		else if(a%d == 0 && d>=b){
			++c;
			if(c==1)
				printf("GOOD");
		}
	}
	
	return 0;
}
