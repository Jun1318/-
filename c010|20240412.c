//https://www.acmicpc.net/problem/1236
#include<stdio.h>
int main(void){
	int x, y;
	int calx = 0;
	int totalh = 0;
	int totaly = 0;
	
	scanf("%d %d", &x, &y);
	char memory[x][y]; // A(3,4)
	
	for(int a=0;a<x;a++){ // 3번 반복 
		scanf("%s", &memory[a]);
		int h = 0;
		for(int b = 0;b<y;b++){ // 4번 반복 
			if(memory[a][b] == 'x' || memory[a][b] == 'X' )
				h++;
		}
		if(h==0)
			totalh++;
	}
	
	for(int c=0;c<y;c++){ // 4번 반복 
		int ye = 0;
		for(int d = 0;d<x-1;d++){ // 3번 반복 
			if(memory[d][c] == 'x' || memory[d][c] == 'X' )
				ye++;
		}
		if(ye==0)
			totaly++;
	}
	
	(totalh>totaly)? printf("%d", totalh) : printf("%d", totaly);
}
