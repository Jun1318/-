#include<stdio.h>

char print[35];
int tb[10000000][2];
int n, total, pos;

void hanoi(int num, int p, int t, int g){
   if(num == 1) tb[pos][0] = p, tb[pos++][1] = g, total++;
   else{
      hanoi(num-1, p, g, t); // 바로 아래 있는탑 
      tb[pos][0] = p, tb[pos++][1] = g, total++;
      hanoi(num-1, t, p, g); // 바로 아래있는탑  
   }
}

void pp(void){
   print[pos++] = '1';
   
   for(int i=0; i<n; i++){
      int p = 0;
      for(int j=0; j<pos; j++){
         int temp = (print[j] - '0')*2 + p;
         
         print[j] = (temp%10) +'0', p = temp/10;
      }
      
      if(p)   print[pos++] = p + '0';
   }
   
   print[0] -= 1;
}

int main(void){
   scanf("%d", &n);
   if(n <= 20){
      hanoi(n, 1, 2, 3);
      
      printf("%d\n", total);
      for(int i =0; i<pos; i++)   printf("%d %d\n", tb[i][0], tb[i][1]);   
   }else{
      pp();
      
      for(int i=pos-1; i>=0; i--)   printf("%c", print[i]);
   }
}
