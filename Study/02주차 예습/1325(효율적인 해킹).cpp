#include <bits/stdc++.h>
using namespace std;

const int M = 1e4 + 1;
vector<int> adj[M];

int dp[M];
bool visit[M];
int sol(int cur){
    visit[cur] = true;
    int ret = 0;
    for(auto &next : adj[cur])
        if(!visit[next])
            ret += sol(next) + 1;
    
    return ret;
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i){
        int u, v;
        scanf("%d%d", &u, &v);

        adj[v].push_back(u);
    }

    int ans = 0;

    for(int i = 1; i <= n; ++i){
        memset(visit, false, sizeof(visit));
        dp[i] = sol(i);
        ans = max(ans, dp[i]);
    }

    for(int i = 1; i <= n; ++i){
        if(ans == dp[i])
            printf("%d ", i);
    }
}

// 설명(DFS)
// 양방향 그래프가 아니기 때문에 각 노드를 기준으로 연결요소들을 카운팅 하면 된다.