#include <bits/stdc++.h>
using namespace std;
bool visit[501][501];
int paper[501][501];
int w, h;
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < h && y < w;
}
int dfs(int x, int y) {
	visit[x][y] = true;
	int ret = 0;

	for(int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(safe(nx, ny) && !visit[nx][ny] && paper[nx][ny]) {
			ret += dfs(nx, ny) + 1;
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &h, &w);
	for(int x = 0; x < h; ++x) {
		for(int y = 0; y < w; ++y)
			scanf("%d", &paper[x][y]);
	}
	
	int area = 0, component = 0;
	for(int x = 0; x < h; ++x) {
		for(int y = 0; y < w; ++y) {
			if(!visit[x][y] && paper[x][y]) {
				area = max(area, dfs(x, y) + 1);
				component++;
			}
		}
	}
	printf("%d\n%d\n", component, area);
}

// 설명(DFS)
// Component의 개수와 Component에 속한 node의 수를 구하는 문제이다.