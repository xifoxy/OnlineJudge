#include <bits/stdc++.h>
using namespace std;
const int M = 1e4 + 1;
vector<int> adj[M];
bool visit[M];
int dp[M];
int n, m;

int sol(int cur){
	int ret = 0;
	visit[cur] = true;
	for(auto &next : adj[cur]){
		if(!visit[next]){
			ret += sol(next) + 1;
		}
	}
	return ret;
}

int main(){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &v, &u);
		adj[u].push_back(v);
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i){
		memset(visit, false, sizeof(visit));
		dp[i] = sol(i);
		ans = max(dp[i], ans);
	}

	for(int i = 1; i <= n; ++i){
		if(ans == dp[i])
			printf("%d ", i);
	}
}

// 설명(Brute Force, DFS)
// 정말 나이브하게 풀었다. 일단 주어진 시간은 5초라 해결은 되지만 SCC로 풀면
// 이 솔루션보다 시간이 대략 1/6정도 줄어들게 된다.
// SCC학습하고 소스추가 해야겠다.