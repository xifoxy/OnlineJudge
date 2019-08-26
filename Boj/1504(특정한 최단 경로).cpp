#include <bits/stdc++.h>
using namespace std;
struct P {
	int vertex, cost;
};
struct cmp {
	bool operator()(const P &a, const P &b) {
		return a.cost > b.cost;
	}
};
const int MAX_V = 8e2, INF = 1e7;
vector<P> adj[MAX_V + 1];

int n, m, u, v, c;

int dijk(int start, int end) {
	int dist[MAX_V + 1];
	bool visit[MAX_V + 1]{0,};
	priority_queue<P, vector<P>, cmp> PQ;

	fill(dist, dist + MAX_V + 1, INF + 1);
	PQ.push({start, 0}); dist[start] = 0;

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
			}
		}
	}
	return dist[end];
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &c);
		adj[v].push_back({u,c});
		adj[u].push_back({v,c});
	}
	int m1, m2;
	scanf("%d%d", &m1, &m2);
	int sum = dijk(1, m1) + dijk(m1, m2) + dijk(m2, n);
	sum = min(sum, dijk(1, m2) + dijk(m2, m1) + dijk(m1, n));
	if(sum >= INF) puts("-1");
	else printf("%d\n", sum);
}

// 설명(Dijkstra's)
// 문제에서 요구하는것은 최단 경로를 구하되, A점과 B점을 거쳐가게 하라고 한다.
// Start->End로 가는 과정에서 AB를 거쳐 가게 하는 방법은
// Start->A->B->End 그리고 Start->B->A->End이다.
// 두개의 경로를 검색해서 최단 경로를 구하면 된다.