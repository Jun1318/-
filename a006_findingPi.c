#include<stdio.h>
#include<stdbool.h>
int main(){
	bool sign = false;
	double total = 0.0;
	for(int a= 1.0;a<1000000000;a+=2){
		if(sign == false){
			total += 1.0/a;
			sign = true;
		}
		else{
			total -= 1.0/a;
			sign = false;
		}
		if(a<=20||a>=999999990)	printf("%d번째 결과값 : %.18f\n",a,  total*4);
		}
}
