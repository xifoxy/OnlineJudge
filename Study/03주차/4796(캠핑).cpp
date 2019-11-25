#include <bits/stdc++.h>
using namespace std;

int L, P, V, T;
int main(){
    while(scanf("%d%d%d", &L, &P, &V), L){
        int ans = V / P * L;
        V %= P;
        printf("Case %d: %d\n", ++T, ans + (V >= L ? L : V));
    }
}

// 말하지 않아도 알아요~