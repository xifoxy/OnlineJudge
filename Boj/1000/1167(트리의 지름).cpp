#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 1;
struct node{
	int v, cost;
};
vector<node> adj[M];
bool visit[M];
int dp[M];
int n, ans;
void sol(int cur, int cost){
	visit[cur] = true;
	for(auto &next : adj[cur]){
		if(!visit[next.v]){
			dp[next.v] = max(dp[next.v], cost + next.cost);
			if(dp[ans] > dp[next.v]) ans = next.v;
			sol(next.v, dp[next.v]);
		}
	}
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int u, v, c;
		scanf("%d", &u);
		while(1){
			scanf("%d", &v);
			if(v == -1) break;
			scanf("%d", &c);
			adj[u].push_back({v, c});
		}
	}
	sol(1, 0);
	memset(visit, false, sizeof(visit));
	memset(dp, 0, sizeof(dp));
	sol(ans, 0);
	printf("%d\n", dp[ans]);
}

// 설명(DFS)
// 좀더 깔끔하게 할수 있는데 귀찮아서(사실 지금 머리 안돌아가서) 좀 드릅게 만들었다.
// DFS한번 돌리면서 가장먼 값들 두개를 추려서 두개를 더한값을 반환해주면 된다.
// 나는 임의의 루트 부터 가장 먼곳을 구하고
// 가장 먼 노드를 다시 루트로 두고 가장 먼 거리까지 값을 계산해서 도출했다.