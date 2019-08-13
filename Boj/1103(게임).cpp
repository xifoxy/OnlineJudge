#include <bits/stdc++.h>
using namespace std;
char mp[51][51];
int d[51][51];
bool visit[51][51], cycle;
int n, m;
int dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m && mp[x][y] != 'H';
}

int dfs(int x, int y) {
	// 방문했던곳을 또 방문하면 사이클이다.
	if(visit[x][y]) {
		cycle = true;
		return 0;
	}
	int &ret = d[x][y];
	// 재귀DP이기 때문에 초기에 초기화 한 값이 아니면 이게 그 방향의 최대값이 된다.
	if(ret != -1) return ret;
	visit[x][y] = true;
	ret = 0;
	for(int i = 0; i < 4; ++i) {
		int nx = x + (dx[i] * (mp[x][y] - '0'));
		int ny = y + (dy[i] * (mp[x][y] - '0'));
		if(safe(nx, ny) && !cycle) {
			ret = max(ret, dfs(nx, ny) + 1);
		}
	}
	visit[x][y] = false;
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%s", &mp[i]);

	int ans = dfs(0, 0);
	printf("%d\n", cycle ? -1 : ans + 1);
}

// 설명(DFS, DP)
// 이 문제에서 가장 신경 써야 할 부분은 무한히 들어가는 사이클을 어떻게 구분하는가 이다.
// 그런데 곰곰히 생각해보면, visit배열 하나만 이용하면 어렵지 않게 구현 가능하다.
// 내가 방문했던곳을 또 방문하게되면 사이클이 존재한다는 뜻이기 때문이다.
// 나머지는 평범한 DFS탐색이다.