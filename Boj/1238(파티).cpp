#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1e3 + 1, INF = 1e8;
struct P {
	int vertex, cost;
};
struct cmp {
	bool operator()(const P &a, const P &b) {
		return a.cost > b.cost;
	}
};

vector<P> adj[MAX_V];

// 다익스트라
int dijk(int start, int end) {
	priority_queue<P, vector<P>, cmp> PQ;
	bool visit[MAX_V]{0,};
	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);

	PQ.push({start, 0});
	dist[start] = 0;

	while(!PQ.empty()) {
		int cur;
		do {
			cur = PQ.top().vertex;
			PQ.pop();
		} while(!PQ.empty() && visit[cur]);

		if(visit[cur] || visit[end]) break;
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
	int n, m, end;
	scanf("%d%d%d", &n, &m, &end);
	for(int i = 0; i < m; ++i) {
		int u, v, cost;
		scanf("%d%d%d", &u, &v, &cost);

		// 문제의 설명에 나와 있듯, 단방향 그래프 이다.
		adj[u].push_back({v,cost});
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		// 도착지점에 사는 학생은 탐색할 필요가 없다.
		if(i == end) continue;
		ans = max(ans, dijk(i, end) + dijk(end, i));
	}
	printf("%d\n", ans);
}

// 설명(Dijkstra's)
// 오고가는 거리가 최대인 값을 구해야 하기 때문에, 모든 마을에서 도착마을까지 탐색해야 한다.