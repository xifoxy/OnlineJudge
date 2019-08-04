#include <bits/stdc++.h>
using namespace std;
int T, n, m, a;
int d[16][16];
int getsum(int x, int y) {
	int ret = 0;
	for(int i = x; i < x + m; ++i) {
		for(int j = y; j < y + m; ++j) {
			ret += d[i][j];
		}
	}
	return ret;
}
int main() {
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		cin >> n >> m;

		int ans = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				cin >> d[i][j];
			}
		}

		for(int i = 0; i < n - m + 1; ++i) {
			for(int j = 0; j < n - m + 1; ++j) {
				ans = max(getsum(i, j), ans);
			}
		}
		printf("#%d %d\n", tc, ans);
	}
}

//»ı·«