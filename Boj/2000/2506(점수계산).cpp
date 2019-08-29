#include <bits/stdc++.h>
using namespace std;
int num, n, sum, point;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &num);
        if(num) sum += ++point;
        else point = 0;
    }
    printf("%d\n", sum);
}

// 이런거 못풀면 자살해야된다.