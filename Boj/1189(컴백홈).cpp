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

// 설명(DFS, DP)
// (R, 0) -> (0, C)로 갈수 있는 경우의 수를 구해야 한다.
// Input은 5*5가 갈수 있는 모든 경우를 돌려 보는데, 중복을 제거하기 위해 Visit배열
// 로 방문 여부를 확인하며 답을 만들어가면 된다.