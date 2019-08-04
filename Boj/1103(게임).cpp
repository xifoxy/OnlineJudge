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
	if(visit[x][y]) {
		cycle = true;
		return 0;
	}
	int &ret = d[x][y];
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