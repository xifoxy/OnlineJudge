#include <bits/stdc++.h>
using namespace std;
const int M = 5e2 + 1;
int n, m;
bool visit[M];
int main() {
	int tc = 0;
	while(scanf("%d%d", &n, &m)) {
		memset(visit, false, sizeof(visit));
		vector<vector<int>> adj(n + 1);
		queue<int> Q;
		if(!n && !m) break;
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			int vertex = 0, edge = 0;
			if(!visit[i]) {
				ans++;
				Q.push(i);
				while(!Q.empty()) {
					int cur = Q.front();
					Q.pop();

					if(visit[cur]) continue;
					vertex++;
					visit[cur] = true;
					for(auto &p : adj[cur]) {
						edge++;
						Q.push(p);
					}
				}
				if(vertex - 1 != edge / 2) --ans;
			} 			
		}
		printf("Case %d: ", ++tc);
		if(!ans) puts("No trees.");
		else if(ans == 1) puts("There is one tree.");
		else printf("A forest of %d trees.\n", ans);
	}
}

// 설명(BFS)
// 내가 떠올린 접근 방법은 두가지다.
// 컴포넌트에 대한 탐색을 하고 사이클을 찾는 방법과
// 정점과 간선의 갯수를 탐색하여 정점의 수 - 1 == 간선의 수 가 같다는 방법이다.
// 후자를 이용했고 탐색 구조는 너비탐색을 이용했다.
// 공백 하나와 점 하나 추가를 하지않아서 엄청 틀렸다 -0-