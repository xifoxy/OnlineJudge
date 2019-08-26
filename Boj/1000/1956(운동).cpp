#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 4e2 + 1, INF = 1e9;
int dist[MAX_V][MAX_V];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            dist[i][j] = INF;
	for(int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		dist[u][v] = w;
	}

	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int ans = INF;
	for(int i = 1; i <= n; ++i) 
		if(ans > dist[i][i]) ans = dist[i][i];

	printf("%d\n", ans >= INF ? -1 : ans);
}

//component가 형성되는 지점을 찾는문제이다
//플로이드에선 dist[i][i]의 값이 존재한다면.
//사이클이 존재한다.