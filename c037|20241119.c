#include<stdio.h>
#define MAX 100001

int main(void){
	int sis, su, map[MAX][2], q[MAX * 8][2], pos =-1, end =1;
	for(int i=0; i<MAX; i++)	map[i][0] = map[i][1] = MAX;
	
	scanf("%d%d", &su, &sis);
	q[0][0] = su, q[0][1] = 0;
	
	while(++pos != end){
		int cp = q[pos][0], ct = q[pos][1];
		
		if(map[sis][0] < ct || map[cp][0] < ct)	continue;
		
		if(map[cp][0] > ct)	map[cp][0] = ct, map[cp][1] = 1;	
		else if(map[cp][0] == ct)	map[cp][1]++;
	
		q[end][0] = cp -1, q[end++][1] = ct +1;
		if(cp < sis){
			if(cp <= 50000)	q[end][0] = cp * 2, q[end++][1] = ct +1;
			if(cp < MAX-1)	q[end][0] = cp +1, q[end++][1] = ct +1;	
		}
	}
	
	printf("%d\n%d", map[sis][0], map[sis][1]);
}

-------------------


#include<stdio.h>
#define MAX 100001

int main(void){
	int sis, su, map[MAX][2]/*시간이랑 중첨개수*/, q[MAX * 8][2]/*위치랑 시간*/, pos =-1, end =1;
	for(int i=0; i<MAX; i++)	map[i][0] = map[i][1] = MAX;
	
	scanf("%d%d", &su, &sis);
	q[0][0] = su, q[0][1] = 0;
	
	while(++pos != end){
		int cur = q[pos][0], curtime = q[pos][1];
		
		if(map[sis][0] < curtime || map[cur][0] < curtime)	continue;
		
		if(map[cur][0] > curtime)	map[cur][0] = curtime, map[cur][1] = 1;	
		else if(map[cur][0] == curtime)	map[cur][1]++;
	
		if(cur != sis)
			if(cur < sis){
				if(cur <= 50000)	q[end][0] = cur*2, q[end++][1] = curtime +1;
				if(cur < MAX-1)	q[end][0] = cur +1, q[end++][1] = curtime +1;
				q[end][0] = cur -1, q[end++][1] = curtime +1;
			}else	q[end][0] = cur -1, q[end++][1] = curtime +1;
	}
	
	printf("%d\n%d", map[sis][0], map[sis][1]);
}
