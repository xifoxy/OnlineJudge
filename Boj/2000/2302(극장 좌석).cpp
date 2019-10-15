#include <bits/stdc++.h>
using namespace std;
int visit[41];
int dp[41]{1,1};
int ans = 1;
int main(){
    for(int i = 2; i < 41; ++i){
        dp[i] = dp[i-1] + dp[i-2];
    }

    int n, visitor, num;
    cin >> n >> visitor;
    for(int i = 0; i < visitor; ++i){
        cin >> num;
        visit[num] = -1;
    }

    for(int i = 1; i <= n; ++i){
        if(visit[i] == -1) {
            visit[i] = 0;
            ans *= dp[visit[i-1]];
            continue;
        }
        visit[i] = visit[i-1] + 1;
    }

    if(visit[n] != 0)
        ans *= dp[visit[n]];
    cout << ans << '\n';
}

// 설명(DP)
// 문제를 구간의 경우의 수를 구해야 한다.

// 그럼 나뉘어진 구간의 수는 어떻게 구할까?
// 직접 그려보면 알겠지만 고정좌석이 없는 연속된 좌석들의 경우의 수는
// 피보나치 수열의 형태를 띈다(그냥 때려 맞췄다.).