#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1e2 + 1, INF = 1e9;
int adj[MAX_V][MAX_V];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	fill(&adj[0][0], &adj[MAX_V - 1][MAX_V - 1], INF);
	for(int i = 1; i <= n; ++i) adj[i][i] = 0;
	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u][v] = 1;
		adj[v][u] = 1;
	}

	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	int	ans = 0, CMP = INF;
	for(int i = 1; i <= n; ++i) {
		int sum = 0;
		for(int j = 1; j <= n; ++j) {
			sum += adj[i][j];
		}
		if(sum < CMP) {
			ans = i;
			CMP = sum;
		}
	}
	printf("%d\n", ans);
}

//최단거리의 합이 가장 작은 사람이 정답이다.
//모르면 문제 다시 풀자