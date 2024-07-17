//https://www.acmicpc.net/problem/2925
#include<stdio.h>
#define BOX_MAX 1000

int box[BOX_MAX][1];
int result[BOX_MAX];

void box_change(int s_point, int f_point, int a, int b){
	int pre_point = s_point-1, count =1;
	
	while(pre_point < f_point){
		box[pre_point][0] = (count++ * a)%b;
		pre_point++;
	}
}

int print_box(int s_point, int f_point){
	int pre_point = s_point-1, total=0;
	
	while(pre_point < f_point){
		total += box[pre_point][0];
		pre_point++;
	}
	
	return total;
}

int main(void){
	int box_num, order_num, count=0;
	int order_table[5];
	scanf("%d %d", &box_num, &order_num);
	
	for(int i=0;i<order_num;i++){
		int j=0;
		
		while (scanf("%d", &order_table[j]) == 1) {
   			j++;
   			if (getchar() == '\n')
        		break;
		}
		
		switch(order_table[0]){
			case 1:
				box_change(order_table[1], order_table[2], order_table[3],order_table[4]);
				break;
				
			case 2:
				result[count] = print_box(order_table[1], order_table[2]);
				count++;
				break;
		}
	}
	for(int i=0;i<count;i++)
		printf("%d\n", result[i]);
	
}
