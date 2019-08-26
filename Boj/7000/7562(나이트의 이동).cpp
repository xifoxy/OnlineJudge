#include <bits/stdc++.h>
using namespace std;
struct P {
	int x, y;
};
P pos;
int d[301][301], tc, n, sx, sy, ex, ey;
int dx[]{-2,-2,-1,-1,1,1,2,2}, dy[]{-1,1,-2,2,-2,2,-1,1};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}
int bfs() {
	queue<P> Q; Q.push({sx,sy});
	memset(d, 0, sizeof(d));
	d[sx][sy] = 1;
	while(!Q.empty() && !d[ex][ey]) {
		pos = Q.front(); Q.pop();
		for(int i = 0; i < 8; ++i) {
			int nx = pos.x + dx[i];
			int ny = pos.y + dy[i];
			if(safe(nx, ny) && !d[nx][ny]) {
				Q.push({nx,ny});
				d[nx][ny] = d[pos.x][pos.y] + 1;
			}
		}
	}
	return d[ex][ey];
}
int main() {
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &n);
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		printf("%d\n", bfs() - 1);
	}
}

//어렵게 생각할 필요 없는 BFS문제다.
//이동해서 값 갱신하면 된다.