#include <bits/stdc++.h>
using namespace std;
struct P {
	int x, y;
};
const int MX = 101;
int a[MX][MX], n, m;
int d[MX][MX], dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
int main() {
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%1d", &a[i][j]);
			d[i][j] = MX * MX;
		}
	}
	queue<P> Q;
	Q.push({0,0});
	d[0][0] = 0;
	while(!Q.empty()) {
		P t = Q.front(); Q.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			if(safe(nx, ny)) {
				if(a[nx][ny] && d[nx][ny] > d[t.x][t.y] + 1) {
					d[nx][ny] = d[t.x][t.y] + 1;
					Q.push({nx,ny});
				}
				if(!a[nx][ny] && d[nx][ny] > d[t.x][t.y]) {
					d[nx][ny] = d[t.x][t.y];
					Q.push({nx,ny});
				}
			}
		}
	}
	printf("%d\n", d[n - 1][m - 1]);
}

//설명
//전형적인 BFS문제이다. 움직이면서 카운팅할때 1과 0을 잘 구별해서
//이전값보다 큰것만 갱신하면된다. 그러기위해 초기화를 나올 수 있는 값보다
//충분히 큰 값으로 대체하면 된다.