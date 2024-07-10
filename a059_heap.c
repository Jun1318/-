#include<stdio.h>

int pq[100] = {0,};
int count = 0;

void printPQ(void){
	for(int i=0;i<count;i++)
		printf("%5d ", pq[i]);
	printf("\n");
}

void insert(int x){
	int i = count;
	pq[count++] = x;
	
	while(i>0){
		int p = (i-1)/2;
		if(pq[p]>x)
			break;
		pq[i] = pq[p];
		i=p;
	}
	pq[i] = x;
}

int remove(void){
	int max = pq[0];
	int root = pq[--count];
	
	int i = 0;
	while(i*2+1 < count){
		pq[i] = root;
		int left = i*2+1;
		int right = i*2+2;
		int c;
		if(right<count && pq[right]>pq[left])
			c = right;
		else 
			c = left;
		
		if(pq[c]>pq[i]){
			int t = pq[c];
			pq[c] = pq[i];
			pq[i] = t;
			i = c;
		}else
			break;
	}
	return max;
}

int main(void){
	int n, d, k;
	
	printf("입력할 데이터 개수 :");
	scanf("%d", &n);
	getchar();
	
	for(int i=0;i<n;i++){
		printf("데이터 %d : ", i+1);
		scanf("%d", &d);
		getchar();
		insert(d);
	}
	printPQ();
	
	printf("몇번째 큰 값 : ");
	scanf("%d", &k);
	getchar();
	
	for(int i=0;i<k-1;i++)
		remove();
	printf("%d번째 큰 값 = %d\n", k, remove());
}
