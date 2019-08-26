#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 5e3 + 1, INF = 1e9;
struct P {
	int vertex, cost;
};
bool visit[MAX_V];
int dist[MAX_V];
int dijk(vector<P> adj[], int start, int end) {
	struct cmp {
		bool operator()(const P &a, const P &b) {
			return a.cost > b.cost;
		}
	};

	fill(dist, dist + MAX_V, INF);
	memset(visit, false, sizeof(visit));
	priority_queue<P, vector<P>, cmp> PQ;

	dist[start] = 0;
	PQ.push({start, 0});

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
			if(next == -1) continue;
			if(dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				PQ.push({next, dist[next]});
			}
		}
	}
	return dist[end];
}

void eraser(vector<P> adj[], int start) {
	queue<int> Q;
	Q.push(start);
	while(!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for(auto &p : adj[cur]) {
			if(p.vertex == -1) continue;
			if(dist[p.vertex] + p.cost == dist[cur]) {
				Q.push(p.vertex);
				p.vertex = -1;
			}
		}
	}
}

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m)) {
		vector<P> adj[MAX_V], r_adj[MAX_V];
		if(!n && !m) break;
		int start, end;
		scanf("%d%d", &start, &end);
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			adj[u].push_back({v,w});
			r_adj[v].push_back({u,w});
		}
		int ans = dijk(adj, start, end);
		eraser(r_adj, end);
		ans = dijk(r_adj, end, start);
		if(ans == INF) puts("-1");
		else printf("%d\n", ans);
	}
}

//dijk(다익스트라)
//이 문제를 풀면서 가장 혼란 스러웠던 것은..
//최단경로가 하나가 아닐 경우라는 것이다.
//복수의 최단경로이면 그것또한 최단경로가 되기 때문에
//그 경로를 포함한 모든 최단경로가 되는 노드를 지워줘야 한다.