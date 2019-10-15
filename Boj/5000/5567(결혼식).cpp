#include <bits/stdc++.h>
using namespace std;
bool visit[501];
vector<int> adj[501];
int ans;
int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 0; i < m; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visit[1] = true;
    for(auto &cur : adj[1]){
        if(!visit[cur]) ans++;
        visit[cur] = true;

        for(auto &next : adj[cur]){
            if(visit[next]) continue;
            visit[next] = true;
            ans++;
        }
    }

    printf("%d\n", ans);
}

// 설명(Brute Force)
// ROOT노드에 연결된 자녀의 수와, 그 자녀에 연결된 자녀수를 중복제외하고 카운팅 하면된다.
// 주의 사항은, 마지막에 설명에 적혀 있는 
// u->v가 친구이면 v->u도 친구관계이다 라는 양방향 그래프 모델을 제시하는 부분만 주의하면 된다.