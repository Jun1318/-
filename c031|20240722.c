#include<stdio.h>
#define EM_MAX 300000

struct st{
	int em_money;
	int superior;
};

int change_count[EM_MAX];

int main(void){
	int em_num;
	struct st info[EM_MAX];
	
	scanf("%d", &em_num);
	scanf("%d", &info[0].em_money);
	info[0].superior = 0;
	
	for(int i=1;i<=em_num;i++){
		int temp = i, count=0;
		
		scanf("%d %d", &info[i].em_money, &info[i].superior);
		
		while(info[temp].em_money > info[info[temp].superior].em_money){
			count++;
			info[info[temp].superior].em_money = info[temp].em_money;
			if(info[temp].superior == 0)
				break;
			temp = info[temp].superior;
		}
		
		change_count[i-1] = count;
	}
	
	for(int i=0;i<em_num;i++)
		printf("%d\n", change_count[i]);
}
