//https://school.programmers.co.kr/learn/courses/30/lessons/181946
#include <stdio.h>
#include<string.h>
#define LEN_INPUT1 21
#define LEN_INPUT2 11

int main(void) {
    char s1[LEN_INPUT1];
    char s2[LEN_INPUT2];
    scanf("%s %s", s1, s2);
    strcat(s1, s2);
    printf("%s", s1);
    return 0;
}
