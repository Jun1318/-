#include<stdio.h>
#include<string.h>
#define max 100

typedef struct point{
	double x;
	double y;
	char type;
}point;

point classify(char m[]){
	point temp;
	int count=0, minus=1, fraction=1, unit=10;
	
	if(m[count] == '-')
		count++;

	while((m[count]-'0')>=0 || m[count] == '.')
		count++;
	
	temp.type = m[count];
	temp.x = temp.y = 0;
	for(int i=0;i<count;i++){
		if(m[i] == '.'){
			fraction =0;
			continue;
		}
		if(m[i] == '-'){
			minus = -1;
			continue;
		}
		
		switch(fraction){
			case 0:
				temp.x = temp.x + ((double)(m[i]-'0'))/unit;
				unit *= 10;
				break;
			case 1:
				temp.x = temp.x*10 + (m[i]-'0');
		}
	}
	temp.x *= minus;
	fraction=1;
	unit=10;
	minus = 1;
	
	for(int i=count+1;i<strlen(m);i++){
		if(m[i] == '.'){
			fraction =0;
			continue;
		}
		if(m[i] == '-'){
			minus = -1;
			continue;
		}
		
		switch(fraction){
			case 0:
				temp.y = temp.y + ((double)(m[i]-'0'))/unit;
				unit *= 10;
				break;
			case 1:
				temp.y = temp.y*10 + (m[i]-'0');
		}
	}
	temp.y *= minus;
	return temp;
}

int main(void){
	point main;
	char memory[max];
	while(1){
		
		printf("\n사칙연산식 입력(q - 프로그램 종료) : ");
		scanf("%s", memory);
		if(memory[0] == 'q'){
			printf("\n프로그램 종료");
			return 0;
		}
	
		main = classify(memory);
	
		switch(main.type){
			case '+':
				printf("%.2f + %.2f = %.2f\n", main.x, main.y, main.x+main.y);
				break;
			case '-':
				printf("%.2f - %.2f = %.2f\n", main.x, main.y, main.x-main.y);
				break;
			case '/':
				if(main.y == 0)
					printf("0으로는 나눌수 없습니다.\n");
				else
					printf("%.2f / %.2f = %.2f\n", main.x, main.y, main.x/main.y);
				break;
			case '*':
				printf("%.2f * %.2f = %.2f\n", main.x, main.y, main.x*main.y);
		}
	}
}
