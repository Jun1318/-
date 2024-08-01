#include<stdio.h>
#include<math.h>

int checkCode(char Pcode[]);

int main(void){
	char Pcode[14];
	
	printf("주민등록번호를 입력하세요 : ");
	scanf("%s", Pcode);
	
	if(checkCode(Pcode)){
		printf("유효하지 않은 주민등록번호입니다.\n");
		return 1;
	}
	
	printf("유효한 주민등록번호 입니다.");
	return 0;
}

int checkCode(char Pcode[]){
	int total=0;
	int checkNum[12] = {2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5};
	
	for(int i=0;i<12;i++){
		int temp = Pcode[i]-'0';
		total += temp * checkNum[i];
	}
	
	total = 11 - (total%11);
	if(total>=10) total -= 10;
	
	if(total == Pcode[12]-'0')	return 0;
	return 1;
}
