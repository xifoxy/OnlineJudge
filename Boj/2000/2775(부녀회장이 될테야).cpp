#include <bits/stdc++.h>
using namespace std;
int d[15][15];
int tc, n, k;
int main() {
	for(int i = 0; i <= 14; ++i) d[0][i] = i;

	for(int i = 1; i <= 14; ++i) {
		for(int j = 1; j <= 14; ++j) {
			d[i][j] += d[i - 1][j] + d[i][j-1];
		}
	}

	cin >> tc;
	while(tc--) {
		cin >> n >> k;
		cout << d[n][k] << '\n';
	}
}

// 말하지 않아도 알아요~