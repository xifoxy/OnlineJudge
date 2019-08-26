#include <bits/stdc++.h>
using namespace std;
struct P {
	int vertex, cost;
};
const int MAX_V = 5e2 + 1, INF = 1e9;
vector<P> adj[MAX_V];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u - 1].push_back({v - 1,w});
	}

	int dist[MAX_V];
	fill(dist, dist + n, INF);
	dist[0] = 0;

	bool cycle = false;
	for(int i = 0; i < n; ++i) {
		for(int cur = 0; cur < n; ++cur) {
			for(auto &p : adj[cur]) {
				int next = p.vertex;
				int cost = p.cost;
				if(dist[cur] != INF && dist[next] > dist[cur] + cost) {
					dist[next] = dist[cur] + cost;
					if(i == n - 1) cycle = true;
				}
			}
		}
	}

	if(cycle) puts("-1");
	else for(int i = 1; i < n; ++i)
		printf("%d\n", dist[i] == INF ? -1 : dist[i]);
}

//드디어 벨만포드로 넘어왔다.
//효율성은 구데기지만 O(VE)이라는 고정된 시간복잡도 속에서 답을 도출할 수 있는 유용한 알고리즘이다.
//다익스트라와 다르게 사이클을 체크할수 있는 몇 안되는(플로이드 포함) 최단거리 알고리즘이다.
//기본 개념숙지가 가장 중요하다. 기초 문제이지 기억안나면 다시 한번 되풀어봐라.