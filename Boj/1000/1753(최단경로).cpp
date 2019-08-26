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

// ����(Dijkstra's)
// ���ͽ�Ʈ���� ���� �⺻ �����̴�.
// ���ͽ�Ʈ��� �켱����ť�� while�� ���� do while���� ���� ��̷Ӵ�.
// �� �� �κκ��� ť�� O(V^2)�� �����Ͱ� ������
// O(log(V^2)) => 2logV => logV
// �� ���� E -> O(ElogV)��� ������ ����.