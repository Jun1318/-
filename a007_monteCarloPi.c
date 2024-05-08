#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
int compare(int a){
	for(int r=1;r<10;r++)	if(a==pow(10, r))	return true;
	return false;
}
int main(){
	int x, y, total, r = 50;
	srand((unsigned)time(NULL));
	for(int a=1;a<=100000000;a++){
		x = rand()%50+1;
		y = rand()%50+1;
		if((x-r)*(x-r)+(y-r)*(y-r)<= r*r)	total++;
		if(compare(a))	printf("%d에서의 원주율 : %f\n", a, (float)total/a*4);
	}
}
