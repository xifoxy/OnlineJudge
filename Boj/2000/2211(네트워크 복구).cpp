#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1e3 + 1, INF = 0x7fffffff;
struct P {
	int vertex, cost;
};
struct cmp {
	bool operator()(const P &a, const P &b) {
		return a.cost > b.cost;
	}
};
vector<P> adj[MAX_V];
int dist[MAX_V], n, m;
int parent[MAX_V];
bool visit[MAX_V];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int u, v, cost;
		scanf("%d%d%d", &u, &v, &cost);
		adj[u].push_back({v,cost});
		adj[v].push_back({u,cost});
	}

	fill(dist, dist + MAX_V, INF);
	priority_queue<P, vector<P>, cmp> PQ;
	PQ.push({1, 0});
	dist[1] = 0;
	while(!PQ.empty()) {
		int cur;
		do {
			cur = PQ.top().vertex;
			PQ.pop();
		} while(!PQ.empty() && visit[cur]);
		if(visit[cur]) break;
		visit[cur] = true;

		for(auto &p : adj[cur]) {
			int next = p.vertex;
			int cost = p.cost;

			if(dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				PQ.push({next, dist[next]});
				parent[next] = cur;
			}
		}
	}

	printf("%d\n", n - 1);
	for(int i = 2; i <= n; ++i) {
		printf("%d %d\n", parent[i], i);
	}
}

//#다익스트라(Dijkstra's)