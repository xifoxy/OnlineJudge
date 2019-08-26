#include <bits/stdc++.h>
using namespace std;
int d[101], mp[101][101], n, mx, dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
int visit[101][101];
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}
void sol(int x, int y, int h) {
	visit[x][y] = true;
	for(int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(safe(nx, ny) && !visit[nx][ny] && mp[nx][ny] > h) {
			sol(nx, ny, h);
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			scanf("%d", &mp[i][j]);
			d[mp[i][j]]++;
			mx = max(mx, mp[i][j]);
		}
	}
	int ans = 1;
	for(int h = 1; h <= mx; ++h) {
		int component = 0;
		memset(visit, false, sizeof(visit));
		for(int x = 0; x < n; ++x) {
			for(int y = 0; y < n; ++y) {
				if(!visit[x][y] && mp[x][y] > h) {
					component++;
					sol(x, y, h);
				}
			}
		}
		ans = max(component, ans);
	}
	printf("%d\n", ans);
}

//설명
//물에 잠긴 구역이 생겨날때 마다 컴포넌트의 갯수가 가장 많은 경우를 구하는 문제이다.
//전형적인 탐색문제라서 어렵지는 않지만, 출력에 나와있는 예외를 처리해주지 않으면
//틀릴 수 있다.