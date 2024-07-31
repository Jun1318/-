#include<stdio.h>
#include<string.h>
#include<ctype.h>

int passwordCHecker(char password[]);

int main(void){
	char password[30];
	
	while(1){
		printf("패스워드 입력(8글자 이상, 대소문자/숫자/특수문자 포함): ");
		scanf("%s", &password);
		
		switch(passwordChecker(password)){
			case 1:
				printf("8글자 이상이어야 합니다.\n");
				break;
			case 2: 
				printf("영문 대문자가 하나 이상이여야 합니다.\n");
				break;
			case 3:
				printf("영문 소문자가 하나 이상이여야 합니다.\n");
				break;
			case 4:
				printf("숫자가 하나 이상이여야 합니다.\n");
				break;
			case 5:
				printf("특수문자가 하나 이상이여야 합니다.\n");
				break;
			default:
				printf("규칙에 맞는 패스워드 입니다.\n");
				return 0;
		}
	}
}

int passwordChecker(char password[]){
	int checkUpper =0;
	int checkLower =0;
	int checkSpecial =0;
	int checkDigit =0;
	int i;
	
	if(strlen(password)<8)
		return 1;
	
	for(i=0; i<strlen(password); i++){
		if(isupper(password[i]))
			checkUpper =1;
		else if(islower(password[i]))
			checkLower=1;
		else if(isdigit(password[i]))
			checkDigit =1;
		else
			checkSpecial =1;
	}
	
	if(checkUpper ==0)	return 2;
	if(checkLower ==0)	return 3;
	if(checkDigit ==0)	return 4;
	if(checkSpecial ==0)	return 5;
	return 0;
}
