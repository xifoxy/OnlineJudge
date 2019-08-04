#include <bits/stdc++.h>
using namespace std;
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
int farm[1001][1001];
int n, m, seed, tomato, day;
struct P { int x, y; };
queue<P> Q;
bool safe(int x, int y) { return x >= 0 && y >= 0 && x < m && y < n; }
bool bfs() {
	P t;
	while(!Q.empty()) {
		t = Q.front(); Q.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = dx[i] + t.x;
			int ny = dy[i] + t.y;
			if(safe(nx, ny) && !farm[nx][ny]) {
				farm[nx][ny] = farm[t.x][t.y] + 1;
				Q.push({nx,ny});
				day = max(day, farm[nx][ny]);
				seed--;
			}
		}
	}
	return seed ? false : true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> farm[i][j];
			if(farm[i][j] == 1) {
				tomato++;
				Q.push({i,j});
			}
			if(farm[i][j] == 0) seed++;
		}
	}
	if(!seed) cout << (tomato ? 0 : -1) << '\n';
	else {
		bool ans = bfs();
		cout << (ans ? day - 1 : -1);
	}
}

//설명
//기저만 잘 처리하면 구현문제다.
//씨앗이 없을때 토마토가 있느냐 없느냐의 문제와
//씨앗이 남았냐 안남았냐 만 구분하면 된다.