#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 1;
vector<int> adj[M];
int n, m, loot;
bool visit[M];

void dfs(int cur){
    visit[cur] = true;
    printf("%d ", cur);
    for(auto &next : adj[cur])
        if(!visit[next])
            dfs(next);
}

void bfs(int pos){
    queue<int> Q;
    Q.push(pos);
    
    visit[pos] = true;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        printf("%d ", cur);
        for(auto &next : adj[cur])
            if(!visit[next]){
                Q.push(next);
                visit[next] = true;
            }
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &loot);

    for(int i = 0; i < m; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i)
        sort(adj[i].begin(), adj[i].end());
    
    
    dfs(loot);
    memset(visit, false, sizeof(visit));
    puts("");
    bfs(loot);
}

// 설명
// 말하지 않아도 알아요~