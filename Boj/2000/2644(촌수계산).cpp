#include <bits/stdc++.h>
using namespace std;
vector<int> adj[101];
int d[101];
int main() {
	int n, s, e;
	scanf("%*d%d%d%d", &s, &e, &n);
	for(int i = 0; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> Q;
	Q.push(s);
	d[s] = 1;

	while(!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		for(auto &p : adj[cur]) {
			if(!d[p]) {
				d[p] = d[cur] + 1;
				Q.push(p);
			}
		}
	}
	printf("%d\n", d[e] - 1);
}

// 설명(BFS)
// 주어진 컴포넌트에서 노드간의 거리를 계산해주면 된다.