#include <stdio.h>

int main(void){
   int n, compare, temp; // n - 입력받을 수 개수, compare - 비교할 x, temp - 입력받는 수 임시 저장 공간 
   
   scanf("%d%d", &n, &compare); // n, compare 입력받기 
   
   for(int i=0; i<n; i++){ // 총 n번 반복 
      scanf("%d", &temp); // 수 입력받기 
      if(temp < compare) printf("%d ", temp); // 만약 입력받은 수가 compare보다 작다면 temp 출력 
   }
} 
