#include <bits/stdc++.h>
using namespace std;
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
int mi[101][101];
bool visit[101][101];
int n, m, cnt = 1;
struct P { int x, y; };
queue<P> Q;
bool safe(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }
void bfs() {
	P t; Q.push({0,0});
	for(; ; ++cnt) {
		int sz = Q.size();
		for(int i = 0; i < sz; ++i) {
			t = Q.front(); Q.pop();
			for(int i = 0; i < 4; ++i) {
				int nx = dx[i] + t.x;
				int ny = dy[i] + t.y;
				if(safe(nx, ny) && mi[nx][ny] && !visit[nx][ny]) {
					if(nx == n - 1 && ny == m - 1) {
						printf("%d\n", cnt + 1);
						return;
					}
					visit[nx][ny] = true;
					Q.push({nx,ny});
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%1d", &mi[i][j]);
		}
	}
	bfs();
}

//설명
//귀찮아서 bfs소스에 생각나는대로 집어넣었다.