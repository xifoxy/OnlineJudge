#include <bits/stdc++.h>
using namespace std;
const int M = 1e6;
int d[M * 2 + 2], n, num;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &num);
        d[num + M]++;
    }

    for(int i = 0; i < M * 2 + 2; ++i){
        if(d[i])
            printf("%d\n", i - M);
    }
}

// 설명
// 어떤 방법을 써도 상관 없지만..
// 나는 카운팅 소트를 썼다.