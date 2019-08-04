#include <bits/stdc++.h>
using namespace std;
int n, m, k, dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
char f[6][6];
bool visit[6][6];
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n &&  y < m && !visit[x][y] && f[x][y] != 'T';
}
int sol(int x, int y, int cnt) {
	int ret = 0;
	if(cnt == k) {
		if(y == m - 1 && x == 0) return 1;
		return 0;
	}

	for(int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(safe(nx, ny)) {
			visit[nx][ny] = true;
			ret += sol(nx, ny, cnt + 1);
			visit[nx][ny] = false;
		}
	}
	return ret;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; ++i)
		scanf("%s", f[i]);
	visit[n - 1][0] = true;
	int ans = sol(n - 1, 0, 1);
	printf("%d\n", ans);
}

//#완전탐색(DFS)

//주어진 이동횟수로 (R - 1, 0)에서 (0, C - 1)로 갈 수 있는 경우의 수 