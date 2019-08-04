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
		adj[u].push_back({v,cost});
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(i == end) continue;
		ans = max(ans, dijk(i, end) + dijk(end, i));
	}
	printf("%d\n", ans);
}

//#다익스트라(Dijkstra's)

//1~N번 마을까지 파티가 열리는 X번 마을에 까지의 최단거리와
//X번 마을에 부터 1~N까지의 최단거리를 다 구한다.
//두개의 합이 최대가 되는것을 반환하면 된다.

//dijk함수에 중지 조건에 
//if(visit[cur] || visit[end]) break;
//여기서 end조건을 추가하면 68ms가 나오고 추가 하지 않으면 176ms가 나온다.