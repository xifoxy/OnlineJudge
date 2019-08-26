#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1e2 + 1, INF = 1e9;
int dist[MAX_V][MAX_V];
bool visit[MAX_V];
vector<int> adj[MAX_V];
void dfs(int &ret, int pos) {
	visit[pos] = true;
	if(dist[ret][0] > dist[pos][0]) {
		ret = pos;
	}
	for(auto &p : adj[pos]) {
		if(!visit[p])
			dfs(ret, p);
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	fill(&dist[0][0], &dist[MAX_V - 1][MAX_V - 1], INF);

	for(int i = 1; i <= n; ++i) dist[i][i] = 0;
	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		dist[u][v] = 1;
		dist[v][u] = 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for(int i = 1; i <= n; ++i) {
		dist[i][0] = 0;
		for(int j = 1; j <= n; ++j)
			if(dist[i][j] != INF)
				dist[i][0] = max(dist[i][0], dist[i][j]);
	}
		
	vector<int> ans;
	for(int i = 1; i <= n; ++i) {
		if(!visit[i]) {
			int pb = i;
			dfs(pb, i);
			ans.push_back(pb);
		}
	}
	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for(auto &p : ans)
		printf("%d\n", p);
}

//케빈베이컨과 유사하다고 생각하고 풀었었는데
//koistudy에선 정답을 백준에선 오답을 받았다
//코이스터디가 데이터가 부실했는지 원인을 찾지 못하고 너무 해메서 톡방에 질문을 던졌더니..
//케빈 베이컨은 모든걸 다 합한것이고,
//이건 최댓값을 구한다는 차이가 있었다..
//그지같은 문제설명