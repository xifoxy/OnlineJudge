#include <bits/stdc++.h>
using namespace std;
struct info{
    int pos, wei;
};
struct cmp{
    bool operator()(const info a, const info b){
        return a.wei < b.wei;
    }
};
vector<vector<info>> adj;

bool visit[100001];
int n, m;
const int INF = 1e9 + 2;
int bfs(int start, int end){
    priority_queue<info, vector<info>, cmp> PQ;
    PQ.push({start, INF});

    while(!PQ.empty()){
        info t = PQ.top();
        PQ.pop();

        if(t.pos == end){
            return t.wei;
        }
        if(visit[t.pos]) continue;
        visit[t.pos] = true;

        for(auto &next : adj[t.pos]){
            int ncost = min(next.wei, t.wei);
            if(visit[next.pos]) continue;
            PQ.push({next.pos, ncost});
        }
    }
    return 0;
}
int main(){
    scanf("%d%d", &n, &m);
    adj.resize(n + 1);
    for(int i = 0; i < m; ++i){
        int u, v, wei;
        scanf("%d%d%d", &u, &v, &wei);
        adj[u].push_back({v, wei});
        adj[v].push_back({u, wei});
    }
    int st, nd;
    scanf("%d%d", &st, &nd);
    printf("%d\n", bfs(st, nd));
}

// 설명(Shortest Path)
// 이분탐색으로도 풀리는것 같은데.. 난 BFS로 푼것 같다. Dijkstra's 비슷한 구조를 띈다.
// 우선순위 큐를 MAX_HEAP의 구조로 만들어서 큰 값을 가진 다리를 먼저 방문하게 하면 된다.
// 어짜피 작은 값의 다리를 거쳐서 가게되면 큰 값의 다리를 만나도 무용지물이기 때문이다.
// 큰 값의 다리를 먼저 가되, 작은 다리를 만나게 되면 작은 다리의 값으로 다시 갱신해서
// 먼저 뽑혀 나오는 도착섬의 값이 답이 된다.