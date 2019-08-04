#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 3e2 + 1, INF = 1e9;
int dist[MAX_V][MAX_V];
int main() {
	fill(&dist[0][0], &dist[MAX_V - 1][MAX_V], INF);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) dist[i][i] = 0;
	for(int i = 0; i < m; ++i) {
		int u, v, h;
		scanf("%d%d%d", &u, &v, &h);
		if(h) dist[u][v] = dist[v][u] = 0;
		else dist[u][v] = 0, dist[v][u] = 1;
	}

	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int cmd;
	scanf("%d", &cmd);
	for(int i = 0; i < cmd; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", dist[u][v]);
	}
}

//방향성에 따라서 들어가야 하는 값이 다르다
//주어진 문제 조건에 따라 양방향인지? 단방향인지를 보자.