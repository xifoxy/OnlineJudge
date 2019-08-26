#include <bits/stdc++.h>
using namespace std;
const int M = 30;
char building[M][M][M];
int dp[M][M][M];
int n, r, c;
int dx[]{0,0,1,-1,0,0};
int dy[]{1,-1,0,0,0,0};
int dz[]{0,0,0,0,1,-1};
int sx, sy, sz;
int ex, ey, ez;
struct info {
	int z, x, y;
};
bool safe(int z, int x, int y) {
	return x >= 0 && y >= 0 && z >= 0 && z < n && x < r && y < c
		&& (building[z][x][y] == 'E' || building[z][x][y] == '.');
}
int sol(int z, int x, int y) {
	queue<info> Q;
	Q.push({z,x,y});
	while(!Q.empty()) {
		info t = Q.front();
		Q.pop();
		for(int i = 0; i < 6; ++i) {
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			int nz = t.z + dz[i];
			if(safe(nz, nx, ny) && (!dp[nz][nx][ny] || dp[nz][nx][ny] > dp[t.z][t.x][t.y] + 1)) {
				dp[nz][nx][ny] = dp[t.z][t.x][t.y] + 1;
				Q.push({nz,nx,ny});
			}
		}
	}
	return dp[ez][ex][ey];
}
int main() {
	while(1) {
		memset(dp, 0, sizeof(dp));
		scanf("%d%d%d", &n, &r, &c);
		if(!n && !r && !c) break;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < r; ++j) {
				scanf("%s", building[i][j]);
				for(int k = 0; k < c; ++k) {
					if(building[i][j][k] == 'S')
						sx = j, sy = k, sz = i;
					if(building[i][j][k] == 'E')
						ex = j, ey = k, ez = i;
				}
			}
		}
		dp[sz][sx][sy] = 1;
		if(sol(sz, sx, sy))
			printf("Escaped in %d minute(s).\n", dp[ez][ex][ey] - 1);
		else puts("Trapped!");
	}
}

// 설명(BFS)
// 3차원 Flood Fill
// Current 좌표를 기준으로 사방탐색 그리고 윗층 아랫층 
// 탐색하면서 최단거리를 구하면 된다. 