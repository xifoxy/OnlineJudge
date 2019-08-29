#include <bits/stdc++.h>
using namespace std;
int cnt[1001], sum, mx, n;
int main(){
    for(int i = 0; i < 10; ++i){
        scanf("%d", &n);
        cnt[n]++;
        sum += n;
        mx = cnt[mx] < cnt[n] ? n : mx;
    }
    printf("%d\n%d\n", sum / 10, mx);
}

// 말하지 않아도 알아요~