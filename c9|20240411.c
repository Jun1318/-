//c2 코드 다듬은거
#include<stdio.h>
#include<string.h>
int main(void){
	int num;
	char ox[80]; 
	
	scanf("%d", &num);
	
	int memory[num];
	
	for(int a=0;a<num;a++){ 
		int calculate = 1;
		int total = 0;
		scanf("%s", &ox);
		for(int b=0;b<strlen(ox);b++){
			if(ox[b] =='x' || ox[b]=='X')
				calculate = 1;
			else{
				total += calculate;
				++calculate;
			}
		}
		memory[a] = total;
	}
	
	for(int c=0;c<num;c++)
		printf("%d\n", memory[c]);
	
	return 0;
}
