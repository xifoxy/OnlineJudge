#include <bits/stdc++.h>
using namespace std;
int d[501][501];
int f[501][501];
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
int n;
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}
int dfs(int x, int y) {
	int &ret = d[x][y];
	if(ret != 0) return ret;
	for(int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(safe(nx, ny) && f[x][y] < f[nx][ny])
			ret = max(ret, dfs(nx, ny) + 1);
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &f[i][j]);

	int ans = -1;
	for(int x = 0; x < n; ++x) {
		for(int y = 0; y < n; ++y)
			if(d[x][y] == 0)
				ans = max(ans, dfs(x, y) + 1);
	}
	printf("%d\n", ans);
}

// 설명(DP, DFS)
// 큰수에서 더 작은수로 내려갈 수 있거나, 혹은 작은수에서 큰수로 올라갈 수 있게끔
// 점화식을 짜서 DFS돌리면 된다.