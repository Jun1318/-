#include <stdio.h>
#include <string.h>

int main() {
   char str[1000000]; // 문자열 입력받을 문자열 배열 
   
   scanf("%[^\n]", str); // enter키 나오기 전까지 문자 입력받기 - 만약 첫글자가 공백이더라도 word가 0이기 떄문에 총 단어의 개수가 증가하지 않음 
   
   int word =0, total =0; // word - 전 글자가 공백이면 0, 알파벳이면 1 // total - 총 단어개수 

   for(int i=0; i<strlen(str); i++){
      if(str[i] == ' '){
         if(word) total++; // 만약에 현재 글자가 공백이고 전 단어가 알파벳이면 총 단어개수 증가 
      
         word = 0; // 현재 글자가 공백이면 무조건 word 0으로 초기화 
      }
      else word = 1; // 현재 글자가 알파벳이면 word 1으로 초기화 
   }

   printf("%d", total + word); // total 뒤에 word를 추가해서 출력하는 이유는 만약에 마지막에 알파벳이 있는데 공백이 나오지 않았다면 단어가 있어도 총 개수 카운트는 그대로기에 더해줌 
}
