#include <bits/stdc++.h>
using namespace std;
char d[101][101];
int n, dx[]{0,0,1,-1}, dy[]{1,-1,0,0};
bool vi[101][101];
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}
void dfs(int x, int y) {
	vi[x][y] = true;
	for(int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(safe(nx, ny) && !vi[nx][ny] && d[nx][ny] == d[x][y]) {
			dfs(nx, ny);
		}
	}
}
void df(int x, int y) {
	vi[x][y] = true;
	for(int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(safe(nx, ny) && !vi[nx][ny]) {
			if(d[x][y] != 'B' && (d[nx][ny] == 'R' || d[nx][ny] == 'G'))
				df(nx, ny);
			else if(d[x][y] == d[nx][ny])
				df(nx, ny);
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%s", d[i]);

	int component = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(!vi[i][j]) {
				component++;
				dfs(i, j);
			}
		}
	}
	printf("%d ", component);
	component = 0;
	memset(vi, false, sizeof(vi));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(!vi[i][j]) {
				component++;
				df(i, j);
			}
		}
	}
	printf("%d", component);
}

//전형적인 탐색문제.
//주어진 조건대로 2번 탐색하면된다.