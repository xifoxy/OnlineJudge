#include <bits/stdc++.h>
using namespace std;
int tc;
int n, m;
int f(int aj[], int bj[]) {
	int ret = -999999999;

	for(int j = 0; j <= m - n; ++j) {
		int t = 0;
		for(int k = j; k <= j + n; ++k) {
			t += (aj[k - j] * bj[k]);
		}
		ret = max(ret, t);
	}
	return ret;
}
int main() {
	cin >> tc;
	for(int i = 1; i <= tc; ++i) {
		int aj[21], bj[21];
		memset(aj, 0, sizeof(aj));
		memset(bj, 0, sizeof(bj));
		cin >> n >> m;
		for(int j = 0; j < n; ++j)
			cin >> aj[j];
		for(int j = 0; j < m; ++j)
			cin >> bj[j];

		int ans;
		if(n > m) {
			swap(n, m);
			ans = f(bj, aj);
		} else ans = f(aj, bj);
		printf("#%d %d\n", i, ans);
	}
}