#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 5e2 + 1, INF = 1e9;
int dist[MAX_V][MAX_V];
int main() {
	fill(&dist[0][0], &dist[MAX_V - 1][MAX_V], INF);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		dist[u][v] = 1;
	}

	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	

	int ans = 0;
	int d[MAX_V]{0,};
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(dist[i][j] != INF) {
				d[i]++;
				d[j]++;
				if(d[i] == n - 1) ans++;
				if(d[j] == n - 1) ans++;
			}
		}
	}
	printf("%d\n", ans);
}

#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 5e2 + 1;
vector<int> adj[MAX_V];
int d[MAX_V];
bool visit[MAX_V];
void dfs(int cur, int pos) {
	visit[cur] = true;
	for(auto &p : adj[cur]) {
		if(!visit[p]) {
			d[pos]++;
			d[p]++;
			dfs(p, pos);
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}

	for(int i = 1; i <= n; ++i) {
		memset(visit, false, sizeof(visit));
		dfs(i, i);
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(d[i] == n - 1)
			ans++;
	printf("%d\n", ans);
}


// 복습 필요.