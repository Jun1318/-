#include<stdio.h>
int main(void){
	int input, x=0, y=0, bigx=0, tinyx=0, bigy=0, tinyy=0, a, b=0;
	int angle = 0;
	scanf("%d", &input); // 14
	char memory[input];
	scanf("%s", memory);//lflfrrflfrrflf
	int x_memory[input+1];//15
	int y_memory[input+1];//15
	x_memory[0] = 0;
	y_memory[0] = 0;
	for(a=0;a<input;a++){//a<14
		if(memory[a] != 'f'){
			switch(memory[a]){
				case 'r':
					if(angle == 0)
						angle = 3;
					else
						angle -= 1;
						break;
				case 'l':
					if(angle == 3)
						angle = 0;
					else
						angle += 1;
						break;
			}
		}
		else if(memory[a] == 'f'){
			switch(angle){
				case 0:
					x_memory[b+1] = x; //[1]부터 시작 
					y_memory[b+1] = --y;
					b++;
					break;
				case 1:
					x_memory[b+1] = --x; 
					y_memory[b+1] = y;
					b++;
					break;
				case 2:
					x_memory[b+1] = x; 
					y_memory[b+1] = ++y;
					b++;
					break;
				case 3:
					x_memory[b+1] = ++x; 
					y_memory[b+1] = y;
					b++;
					break;	
			}
		}
	}
	for(a=0;a<b+1;a++){
		if(x_memory[a]>bigx)
			bigx = x_memory[a];
		if(x_memory[a]<tinyx)
			tinyx = x_memory[a];
		if(y_memory[a]>bigy)
			bigy = y_memory[a];
		if(y_memory[a]<tinyy)
			tinyy = y_memory[a];
	}
	
	int map[bigy-tinyy+1][bigx-tinyx+1]={0,};
	for(a=0;a<b+1;a++)
		map[y_memory[a]-tinyy][x_memory[a]-tinyx] = 1;
	
	for(int d=bigy-tinyy;d>=0;d--){
		for(int e=0;e<=bigx-tinyx;e++){
			if(map[d][e]==1)	printf(".");
			else printf("#");
		}
		printf("\n");
	}
	return 0;
}
