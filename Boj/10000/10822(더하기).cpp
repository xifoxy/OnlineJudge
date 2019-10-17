#include <bits/stdc++.h>
using namespace std;
char str[102];
int sum;
int main(){
    scanf("%s", &str);
    char *ptr = strtok(str, ",");
    while(ptr != NULL){
        sum += atoi(ptr);
        ptr = strtok(NULL, ",");
    }
    printf("%d\n", sum);
}

// 문자열 자를줄 아는지 물어보는 문제이다.