#include <bits/stdc++.h>
using namespace std;
struct info{
    int wei;
    int val;
};
const int M = 1e2 + 1;
info knap[M];
int n, max_wei;
int dp[M * 1000];

// int dp[M][M * 1000];
// int sol(int cur, int wei){
//     if(cur == n) return 0;
//     int &ret = dp[cur][wei];
//     if(ret != - 1) return ret;
//     ret = 0;
//     if(wei - knap[cur].wei >= 0) 
//         ret = max(sol(cur + 1, wei - knap[cur].wei) + knap[cur].val, sol(cur + 1, wei));
//     else ret = sol(cur + 1, wei);
//     return ret;
// }

int main(){
//  memset(dp, -1, sizeof(dp));
    scanf("%d%d", &n, &max_wei);
    for(int i = 0; i < n; ++i)
        scanf("%d%d", &knap[i].wei, &knap[i].val);
    
    for(int i = 0; i < n; ++i){
        for(int j = max_wei; j >= knap[i].wei; --j){
            dp[j] = max(dp[j], dp[j - knap[i].wei] + knap[i].val);
        }
    }
    printf("%d\n", dp[max_wei]);
}

// 설명(DP, knapsack, NP-완전문제)
// 풀다보니 소스가 두개가 생겼다.
// 주석 처리가 된 소스는 BruteForce -> Dp 적용 사례이고,
// 속도가 너무 느려서 다시 최적화를 한 Dp소스이다.
// 우선 이 문제는 BruteForce로는 제한시간 안에 풀 수 없는 문제이다.
// 물건의 갯수가 총 100개, 이 말은 경우의 수가 2^100이기 때문이다.

// 그렇다면 어떻게 메모이제이션 해야 할까?
// 주석처리된 소스를 예로 들면, ret변수와 관련된 3줄을 없애버리고,
// 정수형 으로 선언하면 BruteForce로 구현된 부분이다. 이렇게 구현하게 되면
// 중복되는 과정이 엄청 많기 때문에 이부분을 메모이제이션 해서 중복 방문을 없애야 한다.

// 메모이제이션을 하기 위해 3가지 정도의 경우가 필요하다. 
// 1. 가방에 공간이 빈다.
//  1-1 물건을 가져간다.
//  1-2 물건을 가져가지 않는다.
// 2. 가방에 공간이 없다.
// 이런식으로 공간을 메꾸면 시간복잡도는 Dp배열사이즈 만큼인 O(NW)가 된다.