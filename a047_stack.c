#include <stdio.h>
#define size 100

int memory[size];

void push(int input, int position){
	memory[position] = input;
}

void pop(int position){
	printf("스택메모리 %d번째 원소 %d 제거됨\n\n", position, memory[position-1]);
	memory[position-1] = 0;
}

int check_full(int position){
	if(position == 101)
		return 1;
	return 0;
}

int check_none(int position){
	if(position == 0)
		return 1;
	return 0;
}

int main(void){
	int position=0;
	while(1){
		char c;
		int input;
		printf("하려는 작업의 알페벳 입력(i-insert / d-delete / q-quit / a-all) : ");
		scanf("%c", &c);
		fflush(stdin);
		switch(c){
			case 'i':
				if(!check_full(position)){
					printf("스택 메모리에 입력하실 정수 입력 : ");
					scanf("%d", &input);
					push(input, position);
					position++;
					fflush(stdin);
					printf("\n");
					break;
				}
				else
					printf("스택 메모리 할당공간 꽉 참\n");
				printf("\n");
				break;
				
			case 'd':
				if(!check_none(position)){
					pop(position);
					position--;
					break;
				}
				else
					printf("스택 메모리에 저장되어 있는 데이터 없음\n\n");
				break;
				
			case 'a':
				if(position == 0){
					printf("메모리에 들어있는 데이터 없음\n\n");
					break;
				}
				for(int num=0;num<position;num++)
					printf("%d%c",memory[num], (num%10==9)?'\n':' ');
					printf("\n\n");
				break;
				
			case 'q':
				return 0;
		}
	} 
}
