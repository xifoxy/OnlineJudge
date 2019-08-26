#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 20001, INF = 1e9;
struct P {
	int v, c;
};
struct cmp {
	bool operator()(const P &a, const P &b) {
		return a.c > b.c;
	}
};
int main() {
	int vertex, edge, start;
	scanf("%d%d%d", &vertex, &edge, &start);
	vector<P> adj[MAX_V];

	int u, v, cost;
	for(int i = 0; i < edge; ++i) {
		scanf("%d%d%d", &u, &v, &cost);
		adj[u].push_back({v,cost});
	}

	int dist[MAX_V];
	bool visit[MAX_V]{0,};
	fill(dist, dist + MAX_V, INF);
	priority_queue<P, vector<P>, cmp> PQ;
	dist[start] = 0;
	PQ.push({start, 0});
	while(!PQ.empty()) {
		int cur;
		do {
			cur = PQ.top().v;
			PQ.pop();
		} while(!PQ.empty() && visit[cur]);
		if(visit[cur]) break;

		visit[cur] = true;
		for(auto &p : adj[cur]) {
			int next = p.v;
			cost = p.c;

			if(dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				PQ.push({next, dist[next]});
			}
		}
	}

	for(int i = 1; i <= vertex; ++i) {
		if(dist[i] == INF) puts("INF");
		else printf("%d\n", dist[i]);
	}
}

// 설명(Dijkstra's)
// 다익스트라의 가장 기본 문제이다.
// 다익스트라는 우선순위큐와 while문 내의 do while문이 제법 흥미롭다.
// 이 이 두부분이 큐에 O(V^2)의 데이터가 들어가더라도
// O(log(V^2)) => 2logV => logV
// 총 간선 E -> O(ElogV)라는 마법을 쓴다.