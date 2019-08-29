#include <bits/stdc++.h>
using namespace std;
struct P {
	int x, y;
};
P pos;
int n, m, c, d[101][101], dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
bool visit[101][101];
bool safe(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }
int flood(int x, int y) {
	int ret = 1;
	queue<P> Q; Q.push({x,y});
	visit[x][y] = true;
	while(!Q.empty()) {
		pos = Q.front();
		Q.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = pos.x + dx[i];
			int ny = pos.y + dy[i];
			if(safe(nx, ny) && !visit[nx][ny] && !d[nx][ny]) {
				ret++;
				visit[nx][ny] = true;
				Q.push({nx,ny});
			}
		}
	}
	return ret;
}
int main() {
	scanf("%d%d%d", &n, &m, &c);
	for(int i = 0; i < c; ++i) {
		int x, y, x1, y1;
		scanf("%d%d%d%d", &x, &y, &x1, &y1);
		for(int j = y; j < y1; ++j) {
			for(int k = x; k < x1; ++k) {
				d[j][k]++;
			}
		}
	}
	vector<int> vec;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(!visit[i][j] && !d[i][j])
				vec.push_back(flood(i, j));
		}
	}
	sort(vec.begin(), vec.end());
	printf("%d\n", vec.size());
	for(auto &p : vec)
		printf("%d ", p);
}

// 설명(BFS)
// 간단하게 설명하면, 여백의 영역을 컴포넌트라고 했을때 컴포넌트의 갯수와,
// 컴포넌트의 사이즈를 구하는 문제이다.