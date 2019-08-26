#define _CRT_SECURE_NO_WARNINGS
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORM(i,a,b) for(int i = (a); i > (b); --i)
#define REPM(i,n) FORM(i,n,0)
#define FORS(i,a,b) for(int i = (a); (b[i]); ++i)
#define REPS(i,s) FORS(i,0,s)
#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1e3, INF = 1e9;
struct P {
	int vertex, cost;
};
struct cmp {
	bool operator()(const P &a, const P &b) {
		return a.cost > b.cost;
	}
};
int main() {
	int n, m, u, v, c;
	scanf("%d%d", &n, &m);
	vector<P> adj[MAX_V + 1];
	for(int i = 0; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &c);
		adj[u].push_back({v,c});
	}

	int dist[MAX_V + 1], start, end;
	priority_queue<P, vector<P>, cmp> PQ;
	bool visit[MAX_V + 1]{0,};

	scanf("%d%d", &start, &end);

	fill(dist, dist + MAX_V + 1, INF + 1);
	PQ.push({start, 0});
	dist[start] = 0;

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
	printf("%d\n", dist[end]);
}

// 설명(Dijkstra's)
//1753최단 경로와 똑같은 문제다.