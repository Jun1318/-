#include<stdio.h>
#include<string.h> 
#define size 100

int memory[size];

void push(int input, int position){
	memory[position] = input;
}

void pop(int position, char c){
	int a, b, total=0;
	a = memory[position-2];
	b = memory[position-1];
	
	switch(c){
		case '+':
			total = a+b;
			break;
		case '-':
			total = a-b;
			break;
		case '*':
			total = a*b;
			break;
		case '/':
			total = a/b;
			break;
		case '%':
			total = a%b;
	}
	
	memory[position-2] = total;
	memory[position-1] = 0;
}

check_able(int position){
	if(position>=2)
		return 1;
	return 0;
}

int main(void){
	char temp[size];
	int position=0;
	while(1){
		int count =0;
		printf("\n입력(a|스택저장원소 q|프로그램종료) : ");
		scanf("%s", temp);
		size_t len = strlen(temp);
		
		while(count<len){
			if('0'<=temp[count] && '9'>=temp[count]){
				push(temp[count]-'0', position);
				position++;
			}
			
			else if(temp[count] == 'a'){
				if(position == 0)
					printf("스택저장원소 없음\n");
				for(int i=0;i<position;i++)
					printf("%d%c", memory[i], (i%10 == 9)?'\n':' ');	
			}
			
			else if(temp[count] == 'q'){
				printf("프로그램 종료");
				return 0; 
			}
				
			else{
				if(check_able(position)){
					pop(position, temp[count]);
					position--;	
				}
				else{
					printf("2개의 정수 메모리에 존재하지 않음 || 프로그램 종료");
					return 0;
				}
			}
			count++;
		}
	}
}
