#include<stdio.h>
int main(void){
	int a =0, all, select, sw=0;
	int memory[20][3];
	
	while(1){
		scanf("%d", &all);
		if(all == 0)
			sw = 1;
		scanf("%d", &select); // 0, 0 입력해야지 프로그램 결과값 나옴 - 해결 방법 모르겠음 
		
		switch(sw){
			case 0:
				if(select%2 == 0){
					memory[a][0] = select-1;
					memory[a][1] = all - select +1;
					memory[a][2] = all - select +2;
				}
				else if(select%2 == 1){
					memory[a][0] = select+1;
					memory[a][1] = all - select;
					memory[a][2] = all - select +1;
				}
				a++;
				break;
			case 1:
				for(int c=0;c<a;c++)
					printf("%d %d %d\n", memory[c][0], memory[c][1], memory[c][2]);
				return 0;
		}
	}
	

	
	return 0;
}
