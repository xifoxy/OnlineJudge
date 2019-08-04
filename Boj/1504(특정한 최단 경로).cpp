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

//#다익스트라(Dijkstra's)

//최단 경로를 구하는데 두 점 A와 B를 거쳐가게 하란다.
//그말은 min((1->A->B->N), (1->B->A->N)) 이렇게 두개의 루트로 답을 구하면 된다는 뜻이다.
//로직은 맞았는데 INF값 설정때문에 두번 틀렸다.
//10억으로 잡았더니 바로 터져버렸는데 생각을 잘못했다.
//vertex <= 800, cost <= 1000 인데 길이 없어서 왔던길 다시 돌아간다고 가정해도
//160만도 안나오는데 10억을 잡았으니 오버플로우가 생길 수 밖에..