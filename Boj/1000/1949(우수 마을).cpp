#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
int n;
int citizen[10001];
int visit[10001];
int dfs(int cur, bool flag) {
	visit[cur] = true;
	int ret = flag ? citizen[cur] : 0;
	for(auto &p : adj[cur]) {
		if(!visit[p]) {
			if(flag) ret += dfs(p, false);
			else ret += max(dfs(p, false), dfs(p, true));
		}
	}
	visit[cur] = false;
	return ret;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &citizen[i + 1]);
	}

	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	printf("%d\n", max(dfs(1, false), dfs(1, true)));
}

// ¼³¸í(DP, DFS)
// È¦Â¦Â¦È¦ È¤Àº, È¦Â¦È¦Â¦ÀÌ Àß ÀÌ·ç¾îÁø ÃÖ´ñ°ªÀ» Ãâ·ÂÇÏ¸é µÈ´Ù.
// ±×·¸°Ô ÇÏ±â À§ÇØ¼­ DFS¸¦ µ¹¸±¶§ È¦Â¦Â¦È¦ÀÌ µÉ ¼ö ÀÖ´Ù´Â°É °¡Á¤ÇÏ°í È£Ãâ ±¸Á¶¸¦ Â¥Áà¾ßÇÑ´Ù.