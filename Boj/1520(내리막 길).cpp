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
    // ��ǥ [n,m]�� �����ϸ� �Դ� ��ε鿡 �����Ѵ�.
	if(x == n - 1 && y == m - 1) return 1;
	int &ret = dp[x][y];
	if(ret != -1) return ret;
    // ���� ��ǥ�� ���� -1�̸� ó���湮 �Ѵٴ� ���̴�.
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

// ����(DP)
// ����� ���� ���ؾ��ϴ� DP�����̴�.