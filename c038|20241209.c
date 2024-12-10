#include<stdio.h>

int main(void){
	int pnum =0, t[100001] ={0}, inum, temp;
	
	scanf("%d", &inum);
	for(int i=0; i<inum; i++)	scanf("%d", &temp), t[temp]++ &1? pnum--: pnum++; // 값 입력받음과 동시에 해당 값의 개수 세기 - 짝수 개면 홀수개수++, 홀수개면 소수개수--
	
	if(pnum)	printf("koosaga"); // 숫자 개수 중 홀수가 하나라도 존재하면 koosaga 출력
	else printf("cubelover"); // else~~
}

/*
조건
1. i번째 카드를 고른경우 i번째 카드와 i번째 카드보다 작은 수의 카드들을 모두 제거한다
2. 더 이상 제거할 카드가 없는 사람이 패배한다
3. 두 사람은 최적의 방법으로 게임을 진행한다
4. 구사과가 먼저 시작한다

---------------------

모든 수들의 개수 중 홀수개가 한개라도 존재한다면 구사과가 승리한다

1
22
33

11
22
33

11
222
33

11
22
3

11
2
3
44
*/
