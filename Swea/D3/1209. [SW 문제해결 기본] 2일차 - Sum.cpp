#include <bits/stdc++.h>
using namespace std;
int d[100][100];
int x[100];
int y[100], tt;
int main() {
	vector<int> vec;
	for(int tc = 1; tc <= 10; ++tc) {
		cin >> tt;
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		int ans = 0;
		for(int i = 0; i < 100; ++i) {
			for(int j = 0; j < 100; ++j) {
				cin >> d[i][j];
				x[i] += d[i][j];
				y[j] += d[i][j];
			}
		}
		int r = 0, l = 0;
		for(int i = 0; i < 100; ++i) {
			r += d[i][i];
			l += d[99 - i][i];
			ans = max(ans, max(x[i], y[i]));
		}
		printf("#%d %d\n", tt, max(ans, max(l, r)));
	}
}

//»ý·«