#include <bits/stdc++.h>
using namespace std;
bool fri[11][11];
bool visit[11];
int n, m;
int sol() {
	int isfri = -1;
	for(int i = 0; i < n; ++i) {
		if(!visit[i]) {
			isfri = i;
			break;
		}
	}
	if(isfri < 0) return 1;

	int ret = 0;
	for(int i = isfri + 1; i < n; ++i) {
		if(fri[i][isfri] && !visit[i] && !visit[isfri]) {
			visit[i] = visit[isfri] = true;
			ret += sol();
			visit[i] = visit[isfri] = false;
		}
	}
	return ret;
}
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		memset(fri, 0, sizeof(fri));
		memset(visit, false, sizeof(visit));
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			fri[u][v] = fri[v][u] = true;
		}
		printf("%d\n", sol());
	}
}