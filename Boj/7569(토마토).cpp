#include <bits/stdc++.h>
using namespace std;
int d[101][101][101], n, m, h, z, o;
int dx[]{-1,0,0,1,0,0}, dy[]{0,-1,1,0,0,0}, dz[]{0,0,0,0,1,-1};
bool safe(int x, int y, int z) {
	return x >= 0 && y >= 0 && z >= 0 && x < n && y < m && z < h;
}
struct P {
	int z, x, y;
};
queue<P> Q;
P pos;
int bfs() {
	int ret = 0;
	while(!Q.empty()) {
		pos = Q.front(); Q.pop();
		for(int i = 0; i < 6; ++i) {
			int nx = pos.x + dx[i];
			int ny = pos.y + dy[i];
			int nz = pos.z + dz[i];
			if(safe(nx, ny, nz) && !d[nz][nx][ny]) {
				d[nz][nx][ny] = d[pos.z][pos.x][pos.y] + 1;
				Q.push({nz,nx,ny});
				ret = max(ret, d[nz][nx][ny]);
				--z;
			}
		}
	}
	return ret;
}
int main() {
	scanf("%d%d%d", &m, &n, &h);
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < m; ++k) {
				scanf("%d", &d[i][j][k]);
				if(d[i][j][k] == 1)
					Q.push({i,j,k}), ++o;
				if(!d[i][j][k]) ++z;
			}
		}
	}
	int ans = bfs();
	if(!z && o) printf("%d\n", ans ? ans - 1 : 0);
	else puts("-1");
}

//7576토마토의 확장판이다.
//이 문제를 틀리는 사람들은 대부분...
//주어진 가로세로높이의 조건을 제대로 넣지않아서 틀리는 경우가 많다.