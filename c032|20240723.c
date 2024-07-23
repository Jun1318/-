//https://www.acmicpc.net/problem/27950
#include<stdio.h>
#define C_MAX 1000

struct st{
	int p_name;
	int c_name[C_MAX][2];
	int c_count;
};

int harvest;

void c_count_reset(struct st node[], int n){
	 for (int i = 0; i < n; i++){
        node[i].c_count = 0;
        node[i].p_name = -1;
    }
}

int cal_distance(struct st node[], int pre_node, int num /*몇번째 자식인지 알려주는거*/){
	int total=0;
	
	if(harvest == 3) // 꽉찻다면 시작노드로 복귀 
		return total+1;
	
	if(node[pre_node].c_count == 0){ // 프리노드일떄 - 시작노드일떄 추가해야할지도 
		if(pre_node != 0){
			node[node[pre_node].p_name].c_name[num][1] = 1; // 부모노드 자식배열에서 현재노드 갔다고 기록 
			harvest++;
			return 2;
		}else
			return 2;
	}
	
	for(int i=0; i<node[pre_node].c_count;i++){ // 부모노드 => 자식노드 탐색 반복문 
		if(node[pre_node].c_name[i][1] == 0)
			total += cal_distance(node, node[pre_node].c_name[i][0], i);
		if(harvest == 3)
			return total+1;
	}
	
	if(pre_node != 0){
		node[node[pre_node].p_name].c_name[num][1] = 1;
		return total+1;
	}else
		return total+1;
}

int main(void){
	int c_num;
	int pre_c, pre_p;
	struct st node[C_MAX];
	int total = 0;
	
	scanf("%d", &c_num);
	c_count_reset(node, c_num);
	harvest = 0;
	
	for(int i=0;i<c_num-1;i++){ // 노드 연결 
		scanf("%d %d", &pre_p, &pre_c);
		pre_p--;
		pre_c--;
		
		node[pre_p].c_name[node[pre_p].c_count][0] = pre_c;
		node[pre_p].c_name[node[pre_p].c_count][1] = 0;
		node[pre_p].c_count++;
		node[pre_c].p_name = pre_p;
	}
	
	while(node[0].c_name[(node[0].c_count)-1][1] == 0){
		total += cal_distance(node, 0, 0);
		harvest = 0;
	}
	
	printf("%d", total);
}
