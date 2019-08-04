#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[33][33][3], ans;
int b[33][33], n;
int dx[]{0,1,1}, dy[]{1,0,1};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}
bool csafe(int x, int y) {
	for(int i = 0; i < 3; ++i) {
		if(b[x + dx[i]][y + dy[i]])
			return false;
	}
	return true;
}
ll dfs(int x1, int y1, int x2, int y2, int dir) {
	if(x2 == n - 1 && y2 == n - 1) return 1;
	ll &ret = d[x2][y2][dir];
	if(ret != -1) return d[x2][y2][dir];
	ret = 0;

	for(int i = 0; i < 3; ++i) {
		if(dir != 2) {
			if(dir == 1 && i == 0) continue;
			if(dir == 0 && i == 1) continue;
		}
		int nx = x2 + dx[i];
		int ny = y2 + dy[i];
		if(safe(nx, ny) && b[nx][ny] == 0) {
			if(i == 2 && csafe(x2, y2))
				ret += dfs(x2, y2, nx, ny, 2);
			else if(i < 2) ret += dfs(x2, y2, nx, ny, i ? i : 0);
		}
	}
	return ret;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &b[i][j]);
	printf("%lld\n", dfs(0, 0, 0, 1, 0));
}