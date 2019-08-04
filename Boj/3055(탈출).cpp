#include <bits/stdc++.h>
using namespace std;
char f[51][51];
int d[51][51], dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
int n, m;
struct P {
	int x, y;
};
P pos;
queue<P> Q, Go;
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
void flood() {
	while(!Q.empty()) {
		pos = Q.front(); Q.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = pos.x + dx[i];
			int ny = pos.y + dy[i];
			if(safe(nx, ny) && f[nx][ny] == '.' && !d[nx][ny] && f[nx][ny] != 'D') {
				d[nx][ny] = d[pos.x][pos.y] + 1;
				Q.push({nx,ny});
			}
		}
	}
}
int sol() {
	pos = Go.front();
	d[pos.x][pos.y] = 1;
	while(!Go.empty()) {
		pos = Go.front(); Go.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = pos.x + dx[i];
			int ny = pos.y + dy[i];
			if(safe(nx, ny) && f[nx][ny] != 'X' && (d[nx][ny] > d[pos.x][pos.y] + 1 || d[nx][ny] == 0)) {
				Go.push({nx,ny});
				d[nx][ny] = d[pos.x][pos.y] + 1;
				if(f[nx][ny] == 'D') {
					return d[nx][ny];
				}
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf(" %c", &f[i][j]);
			if(f[i][j] == '*') {
				d[i][j] = 1;
				Q.push({i, j});
			}
			if(f[i][j] == 'S') {
				Go.push({i,j});
			}
		}
	}
	flood();
	int ans = sol();
	if(ans) printf("%d\n", ans - 1);
	else puts("KAKTUS");
}

//설명
//이런 완탐문제는 효율적인 방법이 무엇이 있을지 항상 생각하게 된다.
//DP배열을 하나를 두고 계산을 할까 하다가 상세조건이 까다로워 지기 때문에
//물과 고슴도치를 따로따로 연산을 했다. 
//(물의 확산시간 > 고슴도치 이동시간) 이라는 조건이 성립하기 때문에
//이 조건만 잘 생각해본다면 제법 쉽게 해결이 된다.