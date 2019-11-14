#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 1;
int dp[M];
int st, nd;
int main(){
    memset(dp, -1, sizeof(dp));
    cin >> st >> nd;

    queue<int> Q;
    Q.push(st);

    dp[st] = 1;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        
        if(cur == nd){
            printf("%d", dp[cur] - 1);
            break;
        }
        
        int idx = cur * 2;
        if(idx < M && dp[idx] == -1){
            dp[idx] = dp[cur] + 1;
            Q.push(idx);
        }

        idx = cur - 1;
        if(idx >= 0 && dp[idx] == -1){
            dp[idx] = dp[cur] + 1;
            Q.push(idx);
        }
        
        idx = cur + 1;
        if(idx < M && dp[idx] == -1){
            dp[idx] = dp[cur] + 1;
            Q.push(idx);
        }
    }
}

// 설명
// 별거 없다, 최단거리 개념이니 너비우선 탐색을 하되,
// 범위를 벗어나지 않게 예외처리만 잘해주면된다.