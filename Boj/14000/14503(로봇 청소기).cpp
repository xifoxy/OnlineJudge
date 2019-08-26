#include <bits/stdc++.h>
using namespace std;
int n, m, px, py, cmd;
int d[51][51], dx[]{-1,0,1,0}, dy[]{0,-1,0,1};
int visit[51][51];
struct P {
	int x, y;
};
P pos;
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
int bfs() {
	int ret = 0;
	queue<P> Q;
	Q.push({px,py});
	d[px][py] = 2;
	while(!Q.empty()) {
		pos = Q.front(); Q.pop();
		int dir = cmd + 1 == 4 ? 0 : cmd + 1;
		bool suc = false;
		for(int i = 0; i < 4; ++i) {
			int nx = pos.x + dx[dir];
			int ny = pos.y + dy[dir];
			if(safe(nx, ny) && !d[nx][ny]) {
				ret++;
				cmd = dir;
				Q.push({nx,ny});
				d[nx][ny] = 2;
				suc = true;
				break;
			}
			dir = dir + 1 == 4 ? 0 : dir + 1;
		}
		if(!suc) {
			int nx = pos.x - dx[cmd];
			int ny = pos.y - dy[cmd];
			if(!safe(nx, ny) || d[nx][ny] == 1)
				return ret;

			Q.push({nx,ny});
		}
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &px, &py, &cmd);
	if(cmd <= 1) cmd = cmd == 0 ? 0 : 3;
	else cmd = cmd == 2 ? 2 : 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d", &d[i][j]);
		}
	}
	printf("%d\n", bfs() + 1);
}

//설명
//거지같은 삼성기출
//풀고나서 보면 정말 쉽다. 그런대 문제 설명이 정말 짜증난다.
//이건 풀이를 보기보단 문제를 이해하는것부터가 시작인것 같다.