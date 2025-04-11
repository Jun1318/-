// 퀸 공격 범위는 십자형 + X자 모양 => check함수에서 그 공격범위 내에 있는지 확인하는거임

#include<stdio.h>
#include<math.h>
#define MAX 16

int route[MAX]; // 내가 현재 지나온 위치 저장하는 배열
int n; // 입력 개수였던가

int check(int pos){ // 지금 내가 위치한 깊이에서 어떤 곳을 밟을 수 있는지 확인하는 함수
	for(int i=1; i<pos; i++)
	if(route[i] == route[pos] || abs(i -pos) == abs(route[i] -route[pos])) return 0;
  // 그 아마 내가 현재 검사하고 있는 위치가 이미 방문했거나 밟을 수 없는 곳이면 0 리턴
	
	return 1;
}

int queen(int n, int pos){
	int total =0;
	
	if(pos >n) return 1; // 만약 현재 위치가 최대 깊이라면(모든 퀸을 배치했을때) 리턴 1(최종 개수 +1 하도록 리턴)
	
	for(int i=1; i<=n; i++){
		route[pos] = i; // 일단 처음부터 끝까지 완전탐색 위해 아무곳이나 값 집어넣어서 검사
		if(check(pos)) total += queen(n, pos+1); // 만약 가능한 위치면 그 위치에 값을 집어넣은 다음 재귀함수 호출
	}
	
	return total;
}

int main(void){
	scanf("%d", &n);

	printf("%d", queen(n, 1));
}
