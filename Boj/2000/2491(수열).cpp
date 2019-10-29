#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 1;
int a[M];
int dp[2][M];
int n;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    int ans = 0;
    for(int i = 1; i < n; ++i){
        if(a[i] == a[i - 1]){
            dp[0][i] = dp[0][i - 1] + 1;
            dp[1][i] = dp[1][i - 1] + 1;
        }
        if(a[i] > a[i - 1]) dp[0][i] = dp[0][i - 1] + 1;
        if(a[i] < a[i - 1]) dp[1][i] = dp[1][i - 1] + 1;

        // 당황하지 마라
        // max(dp[0][1], max(dp[1][i], ans)) 와 같은 구문이다
        ans = max({dp[0][i], dp[1][i], ans});
    }
    printf("%d\n", ans + 1);
}

// 설명(DP)
// 상당히 쉬운 문제이다.
// 클때와, 작을때와 같을때를 구분해서 메모해주면 된다.