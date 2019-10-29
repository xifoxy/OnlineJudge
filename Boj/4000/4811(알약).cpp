#include <bits/stdc++.h>
using namespace std;
long long dp[31][31];
long long sol(int complete, int half){
    if(half == 0 && complete == 0) return 1;
    long long &ret = dp[complete][half];
    if(ret != -1) return ret;
    ret = 0;
    if(complete) ret += sol(complete - 1, half + 1);
    if(half) ret += sol(complete, half - 1);

    return ret; 
}
int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    while(scanf("%d", &n)){
        if(n == 0) break;
        printf("%lld\n", sol(n, 0));
    }
}

// 설명(DP)
// 문제 설명은 이리 저리 꼬아놨는데 잘 읽어보면, 주어진 알약을 먹는 경우의 수가 되겠다.
// 온전한 알약을 먹을땐 반으로 쪼개서 먹으니 온전한 알약 - 1, 반개 + 1이 된다.
// 반개 짜리 알약이 될 수 있는 최대치는 30개 이니 30*30 배열에 메모이제이션 하면된다.