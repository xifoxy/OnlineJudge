#include <bits/stdc++.h>
using namespace std;
int d[500][500];
int n, m, nx, ny;

bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int figure_l(int x, int y) {
	int ret = 0, ret2 = 0;
	if(safe(x + 3, y)) for(int i = x; i <= x + 3; ++i)
		ret += d[i][y];
	if(safe(x, y + 3)) for(int i = y; i <= y + 3; ++i)
		ret2 += d[x][i];
	return ret > ret2 ? ret : ret2;
}

int figure_s(int x, int y) {
	int ret = 0;
	if(safe(x + 1, y + 1))
		ret = d[x][y] + d[x][y + 1] + d[x + 1][y] + d[x + 1][y + 1];
	return ret;
}

int dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
int figure_f(int x, int y) {
	int ret = 0;
	for(int i = 0; i < 4; ++i) {
		int sum = d[x][y];
		for(int j = 0; j < 4; ++j) {
			if(j == i) continue;
			nx = x + dx[j];
			ny = y + dy[j];
			if(safe(nx, ny))
				sum += d[nx][ny];
		}
		ret = max(ret, sum);
	}
	return ret;
}

int gx[]{-1,-1,1,1,1,-1,1,-1}, gy[]{1,-1,1,-1,-1,-1,1,1};
int figure_g(int x, int y) {
	int sum1, sum2, ret = 0;
	sum1 = sum2 = d[x][y];
	bool col = true, row = true;
	for(int i = 0; i < 2; ++i) {
		if(!safe(x + dx[i], y + dy[i]))
			col = false;
		if(!safe(x + dx[i + 2], y + dy[i + 2]))
			row = false;
		if(col) sum1 += d[x + dx[i]][y + dy[i]];
		if(row) sum2 += d[x + dx[i + 2]][y + dy[i + 2]];
	}
	if(col) for(int i = 0; i < 4; ++i) {
		nx = x + gx[i];
		ny = y + gy[i];
		if(safe(nx, ny))
			ret = max(ret, sum1 + d[nx][ny]);
	}
	if(row) for(int i = 4; i < 8; ++i) {
		nx = x + gx[i];
		ny = y + gy[i];
		if(safe(nx, ny))
			ret = max(ret, sum2 + d[nx][ny]);
	}
	return ret;
}

int figure_ss(int x, int y) {
	int ret = 0, sum1 = d[x][y], sum2 = d[x][y];
	if(safe(x + 1, y + 1) && safe(x - 1, y)) {
		sum1 += d[x][y + 1];
		ret = max(ret, sum1 + d[x - 1][y] + d[x + 1][y + 1]);
		ret = max(ret, sum1 + d[x - 1][y + 1] + d[x + 1][y]);
	}
	if(safe(x + 1, y + 1) && safe(x, y - 1)) {
		sum2 += d[x + 1][y];
		ret = max(ret, sum2 + d[x][y - 1] + d[x + 1][y + 1]);
		ret = max(ret, sum2 + d[x + 1][y - 1] + d[x][y + 1]);
	}
	return ret;
}
int f() {
	int ret = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			ret = max(ret, figure_l(i, j));
			ret = max(ret, figure_s(i, j));
			ret = max(ret, figure_f(i, j));
			ret = max(ret, figure_g(i, j));
			ret = max(ret, figure_ss(i, j));
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d", &d[i][j]);
		}
	}
	int ans = f();
	printf("%d\n", ans);
}

#include <bits/stdc++.h>
using namespace std;
int n, m, d[501][501];
int dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
bool visit[501][501];
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
int dfs(int depth, int x, int y) {
	if(depth == 3) return d[x][y];
	int ret = 0;
	for(int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(safe(nx, ny) && !visit[nx][ny]) {
			visit[nx][ny] = true;
			ret = max(ret, dfs(depth + 1, nx, ny) + d[x][y]);
			ret = max(ret, dfs(depth + 1, x, y) + d[nx][ny]);
			visit[nx][ny] = false;
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d", &d[i][j]);

	int ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			visit[i][j] = true;
			ans = max(ans, dfs(0, i, j));
			visit[i][j] = false;
		}
	}
	printf("%d\n", ans);
}

//설명
//문제를 풀고나니 제법 멍청하게 풀었다.
//그냥 가능한 조건의 좌표들을 미리 구해놓고 그걸토대로 탐색만 하면 되는데
//이걸 소스로 구현하려고 했던 내가 멍청하지

//DFS로만 푸는 소스를 추가하였다.
//속도적인 측면은 확실히 구데기다.
//DFS에서 재귀를 2중으로 돌리는걸 설명하자면,
//ㅗ짜는 일방적으로 변화하는 좌표만 가지고는 구현이 힘들다.
//두번째 재귀는 1,1이라는 좌표를 방문했을때
//1,1을 기준으로 4방향중 3개의 방향을 탐색한다.