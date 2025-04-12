#include<stdio.h>
#include<math.h>

int tb[8], a[8], check[8]; // tb - 입력받은 수, a - 선택한 순서대로 수 저장, c - 방문 체크
int n, total;

void cal(void){
	int temp = 0;
	
	for(int i=0; i<n-1; i++) temp += (int)abs(a[i] -a[i+1]); // 절댓값 계산 합치기
	if(total < temp) total = temp;
}

void find(int depth){
	if(depth == n){cal(); return;} // 깊이 최대면 절댓값 검사하고 끝
	
	for(int i=0; i<n; i++) if(!check[i]) // 방문 x일때만 다음 깊이로
	a[depth] = tb[i], check[i] = 1, find(depth +1), check[i] = 0;
}

int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &tb[i]);
	
	find(0);
	
	printf("%d", total);
}
