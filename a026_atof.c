#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define plus 1
#define minus -1
double calculate(char*);
int main(void){
	char memory[3][10] = {"1.234", "-2E4", "3.14E-3"};
	for(int a=0;a<3;a++){
		printf("%s = %f\n", *(memory+a), calculate(memory[a]));
	}
}
double calculate(char* s){
	int sign = plus, demical_point_left=0, count=0, count_sign=plus;
	double demical_point_right=0.0, digit = 10.0, total = 0.0;
	if(*s == '-'){
		sign = minus;
		s++;
	}else{
		if(*s == '+')	s++;
	}
	// +인지 -인지 확인하는거 
	while(*s != '.' && *s != 'e' && *s != 'E' && *s != NULL){
		if(isdigit(*s))	{
			demical_point_left = demical_point_left * 10 + (*s - '0');
		}
		s++;
	}
	// 정수부분 저장하기 
	if(*s == '.'){
		s++; 
		while(*s != 'e' && *s != 'E' && *s != NULL){
			if(isdigit(*s)){
				demical_point_right = demical_point_right + (*s - '0')/digit;
				digit *= 10; 
				s++;
			}
		}
	}
	// 만약 *s가 '.'이면  
	if(*s == 'e' || *s == 'E'){
		s++;
		if(*s == '-'){
			count_sign = minus;
			s++;
		}else if(*s == '+')	s++;
		while(*s != NULL){
			if(isdigit(*s)){
				count = count*10 + (*s-'0');
				s++;	
			}
		}
	}
	total = (double)demical_point_left + demical_point_right;
	total = sign * total * pow(10, count_sign*count);
	return total;
}
