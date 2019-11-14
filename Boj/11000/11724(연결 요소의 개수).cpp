#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 1;
vector<int> adj[M];
bool visit[M];
int n, m;

void dfs(int cur){
    visit[cur] = true;
    for(auto &next : adj[cur])
        if(!visit[next])
            dfs(next);
}

int main(){
    scanf("%d%d", &n, &m);
    for(int idx = 0; idx < m; ++idx){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for(int idx = 1; idx <= n; ++idx){
        if(!visit[idx])
            dfs(idx), ++ans;
    }
    printf("%d\n", ans);
}

// 말하지 않아도 알아요~