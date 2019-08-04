1979. 어디에 단어가 들어갈 수 있을까#include <bits/stdc++.h>
using namespace std;
int tc, d[15][15];
int n, m;
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}
bool r(int x, int y) {
	if(x > 0 && d[x - 1][y] == 1) return false;
	if(x + m < n && d[x + m][y] == 1) return false;
	for(int i = 0; i < m; ++i) {
		if(d[x + i][y] != 1) return false;
	}
	return true;
}
bool l(int x, int y) {
	if(y > 0 && d[x][y - 1] == 1) return false;
	if(y + m < n && d[x][y + m] == 1) return false;
	for(int i = 0; i < m; ++i) {
		if(d[x][y + i] != 1) return false;
	}
	return true;
}
int main() {
	cin >> tc;
	for(int k = 1; k <= tc; ++k) {
		cin >> n >> m;

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j)
				cin >> d[i][j];
		}
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(d[i][j] == 1) {
					if(j + m <= n && l(i, j)) ans++;
					if(i + m <= n && r(i, j)) ans++;
				}
			}
		}
		printf("#%d %d\n", k, ans);
	}
}

//생략