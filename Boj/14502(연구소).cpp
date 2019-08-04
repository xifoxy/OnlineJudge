#include <bits/stdc++.h>
using namespace std;
struct P {
	int x, y;
};
int n, m, dx[]{1,-1,0,0}, dy[]{0,0,1,-1}, virus;
queue<P> vi, Q;
P pos;
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
int flood(vector<vector<int>> v) {
	int ret = virus;
	Q = vi;
	while(!Q.empty()) {
		pos = Q.front(); Q.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = pos.x + dx[i];
			int ny = pos.y + dy[i];
			if(safe(nx, ny) && !v[nx][ny]) {
				v[nx][ny] = 2;
				Q.push({nx,ny});
				ret--;
			}
		}
	}
	return ret - 3;
}
int n_per(vector<vector<int>> &v, int x, int y, int wall = 3) {
	if(wall == 0) {
		return flood(v);
	}
	int ret = 0;
	for(int i = x; i < n; ++i) {
		if(i != x) y = 0;
		for(int j = y; j < m; ++j) {
			if(v[i][j] == 0) {
				v[i][j] = 1;
				ret = max(ret, n_per(v, i, j, wall - 1));
				v[i][j] = 0;
			}
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	vector<vector<int>> vec(n, vector<int>(m));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d", &vec[i][j]);
			if(vec[i][j] == 0) virus++;
			if(vec[i][j] == 2) vi.push({i,j});
		}
	}
	printf("%d\n", n_per(vec, 0, 0));
}

//설명
//종만북을 공부하면서 바뀐 사고방식은(완탐으로 가능한가?)
//문제를 읽고 완탐으로 해결 가능한가? 라는 사고방식을 가지는거부터가
//문제해결 능력의 시작이자 솔루션의 시간을 줄여가는 단초이다.
//문제 조건을 잘 보면 64개중에 3개를 골라라
//이말은 64개중에 3개를 고를 수 있는 경우의 수 이다.
//범위가 작으니 그냥 조합으로 구하고 매번 확산시켜보면된다.