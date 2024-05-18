#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int my_atoi(char*);
char* my_itoa(int);
int main(void){
	char memory[30];
	printf("atoi() : %d\n", atoi("123456789"));
	printf("my_atoi() : %d\n", my_atoi("123456789"));
	itoa(123456789, memory, 10);
	printf("itoa() = %s\n", memory);
	printf("my_itoa() = %s\n", my_itoa(123456789));
}

int my_atoi(char* m){
	int total=0;
	while(*m)	if(*m>='0' && *m<='9')	total = total*10 + *m++ - 48;
	return total;
}

char* my_itoa(int i){
	int size, replica = i;
	while(replica){
		replica /= 10;
		size++;
	}
	char* total = (char*)malloc(size+1);
	total[size] = '\0';
	while(size--){
		total[size] = i%10 + '0';
		i /= 10;
	}
	return total;
}
