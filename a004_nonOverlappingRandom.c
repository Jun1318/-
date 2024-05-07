#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int memory[10] = {0,};
	int random_num, count=0;
	srand(time(0));
	for(int a=0;a<10;a++){
		do{
			count = 0;
			random_num = rand()%10;
			if(memory[random_num] == 0){
				printf("%d\t", random_num+1);
				memory[random_num] = 1;
				count = 1;
			}
		}while(count != 1);
	}
}
