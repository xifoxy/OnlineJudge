#include <bits/stdc++.h>
using namespace std;
int n, m, jump, ans;
int d[101][101][101];
int dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
char MP[102][102];
string boggle;
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
int sol(int x, int y, int next) {
	int &ret = d[x][y][next];
	if(next == boggle.size() - 1) return 1;
	if(ret != -1) return ret;

	ret = 0;
	for(int i = 0; i < 4; ++i) {
		for(int j = 1; j <= jump; ++j) {
			int nx = x + (dx[i] * j);
			int ny = y + (dy[i] * j);
			if(safe(nx, ny) && MP[nx][ny] == boggle[next + 1]) {
				ret += sol(nx, ny, next + 1);
			}
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> jump;
	for(int i = 0; i < n; ++i)
		cin >> MP[i];
	cin >> boggle;

	memset(d, -1, sizeof(d));
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(MP[i][j] == boggle[0])
				ans += sol(i, j, 0);

	cout << ans << '\n';
}

// 설명
// 완전 나이브하게 풀었다가 몇번 털리고
// DP적용하는데 이해가 부족했다.