#include <bits/stdc++.h>
using namespace std;
struct info {
	int x, y;
	int jump;
};
int board[200][200];
int dp[200][200][31];

// 원숭이
int dx[]{1,-1,0,0}, dy[]{0,0,1,-1};

// 말은 총 8곳으로 뛸 수 있다.
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
            // BFS특성상 도착시 바로 답을 출력하면 된다.
			ans = dp[cur.x][cur.y][cur.jump];
			break;
		}

		if(cur.jump) {
            // 점프가 가능할때
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

// 설명(BFS)
// 이문제는 어렵기보단 짜증나는 문제다. 마치 카카오 코테를 보는듯한 기분이다.
// 2D visit 배열이 필요하다. 점프를 했을때 이동한곳을 체크해줘야 하기 때문이다.