//https://www.acmicpc.net/problem/12019
#include<stdio.h>
#include<limits.h>
#define P_MAX 100
#define TRI_MAX 10100

int dP[P_MAX];
int DC, RC;
int tri[TRI_MAX];

int dp(int day, int rC, int pre, int tri_pos){
	if(DC-day < RC-rC)	return INT_MAX;
	if(DC== day)	return rC==RC? 0: INT_MAX;
	
	int temp=0;
	int temp1 = dp(day+1, rC, pre+dP[day], tri_pos*2 +1); // 내일 리셋안한거 
	if(rC<RC){
		int temp2 = dp(day+1, rC+1, 0, tri_pos*2 +2); // 내일 리셋한거 
		if(temp2<temp1){
			temp1 = temp2;
			temp++;
		}
	}
	
	if(temp!=0)	tri[tri_pos*2 +2]++;
	else tri[tri_pos*2 +1]++;
	
	return temp1 + dP[day]*pre;
}

int main(void){
	int tricount=0, daycount=0;
	
	scanf("%d %d", &DC, &RC);
	for(int i=0;i<DC; i++)
		scanf("%d", &dP[i]);
	
	printf("%d\n", dp(0, 0, 0, 0));
	
	for(int i=0;i<DC;i++){
		if(tri[tricount*2+1]== 1){
			daycount++;
			tricount = tricount*2 +1;
		}else{
			tricount = tricount*2 +2;
			printf("%d ", ++daycount);
		}
	}
}
