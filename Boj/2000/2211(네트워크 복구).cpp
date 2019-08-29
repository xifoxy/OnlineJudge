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

// 설명(Dijkstra's)
// 문제에서 주어지는 조건은 2개이다.
// 1. 끊어진 간선을 N - 1개로 연결해서 모든 컴퓨터를 연결해야한다.
// 2. 복구된 간선의 길이가 최단거리가 되어야 한다.
// 두 조건을 갖추기 위해 다익스트라와 Prev배열을 이용했다.