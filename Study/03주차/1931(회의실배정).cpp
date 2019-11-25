#include <bits/stdc++.h>
using namespace std;
struct info{
    int s, e;
};
const int M = 1e5 + 1;
info d[M];
int n;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d%d", &d[i].s, &d[i].e);

    sort(d, d + n, [](const info &a, const info &b){
        return a.e == b.e ? a.s < b.s : a.e < b.e;
    });
    int ans = 1, End = d[0].e;
    for(int i = 1; i < n; ++i){
        if(d[i].s >= End){
            End = d[i].e;
            ans++;
        }
    }
    printf("%d\n", ans);
}

// 설명
// 빨리 끝나는 순서대로 배정하면 된다.