#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX_V = 1e5 + 1, INF = 1e13;

struct P {
	ll vertex, cost;
};
struct cmp {
	bool operator()(const P &a, const P &b) {
		return a.cost > b.cost;
	}
};

int height[MAX_V];
bool visit[MAX_V];
int n, m, d, e;
vector<P> adj[MAX_V];

void dijk(vector<ll> &vec, int start) {
	memset(visit, false, sizeof(visit));
	priority_queue<P, vector<P>, cmp> PQ;
	PQ.push({start, 0});
	vec[start] = 0;

	while(!PQ.empty()) {
		int cur;
		do {
			cur = PQ.top().vertex;
			PQ.pop();
		} while(!PQ.empty() && visit[cur]);
		if(visit[cur]) break;
		visit[cur] = true;

		for(auto &p : adj[cur]) {
			ll next = p.vertex;
			ll cost = p.cost;
			if(height[cur] < height[next] && vec[next] > vec[cur] + cost) {
				vec[next] = vec[cur] + cost;
				PQ.push({next, vec[next]});
			}
		}
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &d, &e);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &height[i]);
	for(int i = 0; i < m; ++i) {
		int u, v, cost;
		scanf("%d%d%d", &u, &v, &cost);
		adj[u].push_back({v,cost});
		adj[v].push_back({u,cost});
	}

	vector<ll> start(n + 1, INF), end(n + 1, INF);
	dijk(start, 1);
	dijk(end, n);
	ll ans = -INF;
	for(int i = 2; i <= n; ++i) {
		if(start[i] == INF || end[i] == INF) continue;
		ans = max(ans, height[i] * e - (start[i] + end[i]) * d);
	}
	if(ans == -INF) puts("Impossible");
	else printf("%lld\n", ans);
}

//#다익스트라(Dijkstra's)
//간단한 방법이다.
//둘다 올라가면된다.