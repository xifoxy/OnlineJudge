#include <bits/stdc++.h>
using namespace std;
struct info{
    int num;
    int cnt;
};
info coin[101];
int dp[101][10001];
int main(){
    int T, K;
    scanf("%d%d", &T, &K);

    for(int idx = 1; idx <= K; ++idx){
        scanf("%d%d", &coin[idx].num, &coin[idx].cnt);
    }

    // 스스로를 체크할때 쓰이기 위한 기저사례
    dp[0][0] = 1;
    for(int idx = 1; idx <= K; ++idx){
        for(int cnt = 0; cnt <= coin[idx].cnt; ++cnt){
            for(int val = 0; coin[idx].num * cnt + val <= T; ++val){
                dp[idx][val + coin[idx].num * cnt] += dp[idx - 1][val];
            }
        }
    }
    printf("%d\n", dp[K][T]);
}

// 설명(DP)
// 주어진 동전 K종류를 섞어 T원을 만들수 있는 경우의 수를 만들어야 하는 문제이다.
// 그러니까 dp[N][K] = N종류의 동전으로 K원 만들기 정도 되겠다
// 조건을 짜보면...
// dp[N종류][K원 + 현재 내가 만들수 있는 값] += dp[N-1 종류][K원] 이다.
