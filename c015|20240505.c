#include<stdio.h>
int main(void){
	int len, turn_opportunity, temp;	
	scanf("%d %d", &len, &turn_opportunity);
	char memory[len];
	int memory2[len];
	scanf("%s", &memory);
	for(int a=0;a<len;a++)
		memory2[a] = (int)memory[a];
	for(int a=0;a<len-1;a++){
		if((int)memory[a] + turn_opportunity >= 91){
			turn_opportunity += (int)memory[a] - 91;
			memory2[a] = 65;
			}
		else if((int)memory[a]+turn_opportunity<91)
			continue;
	}
	temp = turn_opportunity%26;
	(temp+(int)memory[len-1]>90)? memory2[len-1]=temp+(int)memory[len-1]-26:memory2[len-1]=temp+(int)memory[len-1];
	for(int a=0;a<len;a++){
		printf("%C", (char)memory2[a]);
	}
	return 0;
}
