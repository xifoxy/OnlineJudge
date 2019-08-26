#include <bits/stdc++.h>
using namespace std;
int d[101][101], n, m, k, ans;
int dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
int visit[101][101];
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
int dfs(int x, int y) {
	visit[x][y] = true;
	int ret = 1;
	for(int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(safe(nx, ny) && d[nx][ny] && !visit[nx][ny]) {
			ret += dfs(nx, ny);
		}
	}
	return ret;
}
int main() {
	cin >> n >> m >> k;
	for(int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		d[x - 1][y - 1] = 1;
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(d[i][j] && !visit[i][j]) {
				ans = max(ans, dfs(i, j));
			}
		}
	}
	cout << ans;
}

// 설명(DFS, BFS)
// 서로붙어 있는 음식물들은 하나의 음식물로 취급한다.
// 그렇다면 가장 큰 음식물은 가장 큰 컴포넌트가 된다는 뜻이다.