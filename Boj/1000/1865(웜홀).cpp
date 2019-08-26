#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 5e2 + 1, INF = 1e9;
struct P {
	int vertex, cost;
};

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, m, hall;
		scanf("%d%d%d", &n, &m, &hall);
		vector<P> adj[MAX_V];
		int dist[MAX_V];

		fill(dist, dist + n, INF);
		int u, v, w;
		for(int i = 0; i < m; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			adj[u - 1].push_back({v - 1,w});
			adj[v - 1].push_back({u - 1,w});
		}
		for(int i = 0; i < hall; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			adj[u - 1].push_back({v - 1, -w});
		}

		dist[0] = 0;
		bool cycle = false;
		for(int i = 0; i < n; ++i) {
			for(int cur = 0; cur < n; ++cur) {
				for(auto &p : adj[cur]) {
					int next = p.vertex;
					int cost = p.cost;
					if(dist[cur] != INF && dist[next] > dist[cur] + cost) {
						dist[next] = dist[cur] + cost;
						if(i == n - 1) cycle = true;
					}
				}
			}
		}
		printf("%s\n", cycle ? "YES" : "NO");
	}
}

// 설명
// 워우 유사코 골드문제이지만 생각보다 어렵지 않다
// 음수 사이클이 있으면 답을 출력하면된다.