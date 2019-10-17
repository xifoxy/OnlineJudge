#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, seq = 2;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        seq = (seq * 2) - 1;
    }
    printf("%d\n", seq * seq);
}

// 말하지 않아도 알아요~