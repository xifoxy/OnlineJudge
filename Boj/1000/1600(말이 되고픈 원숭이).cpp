#include <bits/stdc++.h>
using namespace std;
struct info {
	int x, y;
	int jump;
};
int board[200][200];
int dp[200][200][31];

// ������
int dx[]{1,-1,0,0}, dy[]{0,0,1,-1};

// ���� �� 8������ �� �� �ִ�.
int jx[]{-1,-2,-2,-1,1,2,2,1};
int jy[]{-2,-1,1,2,-2,-1,1,2};
int k, w, h;

bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < h && y < w && !board[x][y];
}
int main() {
	scanf("%d%d%d", &k, &w, &h);

	for(int x = 0; x < h; ++x) {
		for(int y = 0; y < w; ++y) {
			scanf("%d", &board[x][y]);
		}
	}

	queue<info> Q;
	Q.push({0,0,k});
	dp[0][0][k] = 1;

	int ans = 0;
	while(!Q.empty()) {
		info cur = Q.front();
		Q.pop();

		if(cur.x == h - 1 && cur.y == w - 1) {
            // BFSƯ���� ������ �ٷ� ���� ����ϸ� �ȴ�.
			ans = dp[cur.x][cur.y][cur.jump];
			break;
		}

		if(cur.jump) {
            // ������ �����Ҷ�
			for(int direction = 0; direction < 8; ++direction) {
				int nx = cur.x + jx[direction];
				int ny = cur.y + jy[direction];
				if(safe(nx, ny) && !dp[nx][ny][cur.jump - 1]) {
					dp[nx][ny][cur.jump - 1] = dp[cur.x][cur.y][cur.jump] + 1;
					Q.push({nx,ny,cur.jump - 1});
				}
			}
		}
		for(int direction = 0; direction < 4; ++direction) {
			int nx = cur.x + dx[direction];
			int ny = cur.y + dy[direction];
			if(safe(nx, ny) && !dp[nx][ny][cur.jump]) {
				dp[nx][ny][cur.jump] = dp[cur.x][cur.y][cur.jump] + 1;
				Q.push({nx,ny,cur.jump});
			}
		}
	}
	printf("%d\n", ans == 0 ? -1 : ans - 1);
}

// ����(BFS)
// �̹����� ��Ʊ⺸�� ¥������ ������. ��ġ īī�� ���׸� ���µ��� ����̴�.
// 2D visit �迭�� �ʿ��ϴ�. ������ ������ �̵��Ѱ��� üũ����� �ϱ� �����̴�.