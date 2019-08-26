#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;
int n, m, a, b, package = M, piece = M;

int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d", &a,&b);
        package = min(a, package);
        piece = min(b, piece);
    }

    int ans = n / 6;
    n %= 6;

    ans = min(package * ans, piece * 6 * ans);
    if(n) ans += min(package, piece * n);
    printf("%d\n", ans);
}

// 너무쉬우니 생략