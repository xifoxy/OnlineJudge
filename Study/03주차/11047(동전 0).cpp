#include <bits/stdc++.h>
using namespace std;
int n, K;
int d[10];
int main(){
    scanf("%d%d", &n, &K);
    for(int i = 0; i < n; ++i)
        scanf("%d", &d[i]);

    int ans = 0;
    for(int i = n - 1; i >= 0; --i){
        if(d[i] <= K){
            ans += (K / d[i]);
            K = K % d[i];
        }
    }
    printf("%d\n", ans);
}

// 설명
// 가장 큰 동전부터 빼면 되는데 그 이유는...
// D[i]원은 D[i-1]원의 배수이기 때문이다.