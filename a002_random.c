#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int memory[30];
	srand(time(0));
	for(int a=0;a<30;a++){
		memory[a] = 1+rand()%6;
	}
	for(int a=0;a<30;a++){
		printf("%d\n", memory[a]);
	}
}
