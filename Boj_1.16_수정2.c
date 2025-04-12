// 그냥 수 입력받으면 해당 인덱스 위치 1로 바꿔서 값 있는거 표시하는건데
// 수가 음수까지니 그냥 +1000000해서 모든 값 0부터 시작하는 배열에 입력받도록 하는거

#include<stdio.h>

int tb[2000001];
int n, temp;

int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &temp), tb[temp +1000000] = 1;
	
	for(int i=0; i<=2000000; i++) tb[i] && printf("%d\n", i -1000000);
}
