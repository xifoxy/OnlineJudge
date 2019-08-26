#include <bits/stdc++.h>
using namespace std;
const int M = 501;
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
int board[M][M], dp[M][M], n, m;
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n &&  y < m;
}
int sol(int x, int y) {
    // 좌표 [n,m]에 도착하면 왔던 경로들에 갱신한다.
	if(x == n - 1 && y == m - 1) return 1;
	int &ret = dp[x][y];
	if(ret != -1) return ret;
    // 현재 좌표의 값이 -1이면 처음방문 한다는 뜻이다.
	ret = 0;

	for(int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(safe(nx, ny) && board[x][y] > board[nx][ny]) {
			ret += sol(nx, ny);
		}
	}

	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d", board[i] + j);

	printf("%d\n", sol(0, 0));
}

// 설명(DP)
// 경우의 수를 구해야하는 DP문제이다.