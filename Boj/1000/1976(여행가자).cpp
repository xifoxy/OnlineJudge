#include <bits/stdc++.h>
using namespace std;
int city, root;
vector<int> adj[201];
int travel_root[1001];
bool visit[201];
bool dfs(int cur, int end) {
	if(cur == end) return true;
	bool ret = false;
	visit[cur] = true;

	for(auto &pos : adj[cur]) {
		if(visit[pos]) continue;
		if(ret) break;
		ret = dfs(pos, end);
	}
	return ret;
}
int main() {
	scanf("%d%d", &city, &root);
	for(int cur = 1; cur <= city; ++cur) {
		for(int next = 1; next <= city; ++next) {
			int a;
			scanf("%d", &a);
			if(a) adj[cur].push_back(next);
		}
	}

	for(int i = 1; i <= root; ++i)
		scanf("%d", &travel_root[i]);

	bool ans = true;
	for(int i = 2; i <= root; ++i) {
		memset(visit, false, sizeof(visit));
		int start = travel_root[i - 1];
		int end = travel_root[i];
		if(dfs(start, end) == false) {
			ans = false;
			break;
		}
	}
	if(ans) puts("YES");
	else puts("NO");
}

// 설명(Brute Force, DFS)
// 주어진 방문순서를 다 방문할 수 있는지 확인하는 문제이다.
// 완전탐색으로 해결이 가능하다.