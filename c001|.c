#include<stdio.h>
int main(void){
	int num, d, e;
	scanf("%d", &num);
	int a[num];
	
	for(int b=0;b<num;b++){
		scanf("%d", &a[b]);
	}
	
	d = a[0];
	e = a[0];
	
	for(int c=0;c<num;c++){
		if(a[c]>=d)
			d = a[c];
	}
	
	for(int g=0;g<num;g++){
		if(a[g]<=e)
			e = a[g];
	}
	
	printf("%d %d", e, d);
	
	return 0;
	
}
