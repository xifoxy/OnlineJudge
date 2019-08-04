#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 4e2 + 1, INF = 1e9;
int dist[MAX_V][MAX_V];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	fill(&dist[0][0], &dist[MAX_V - 1][MAX_V - 1], INF);

	for(int i = 1; i <= n; ++i) dist[i][i] = 0;

	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		dist[u][v] = 1;
	}

	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}


	int s; scanf("%d", &s);
	for(int i = 0; i < s; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		if(dist[u][v] != INF || dist[v][u] != INF) {
			printf("%d\n", dist[u][v] != INF ? -1 : 1);
		} else puts("0");
	}
}

//거리가 양쪽다 갱신되는 경우에 대해서 생각해보면 된다.