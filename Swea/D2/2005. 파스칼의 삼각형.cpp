#include <bits/stdc++.h>
using namespace std;
int T, n;
int d[16][16];
int main() {
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		cin >> n;

		cout << '#' << tc << '\n';
		d[0][0] = 1;
		cout << d[0][0] << '\n';
		for(int i = 1; i < n; ++i) {
			for(int j = 0; j <= i; ++j) {
				if(j == 0) d[i][j] = d[i - 1][j];
				else if(j == i) d[i][j] = d[i - 1][j - 1];
				else
					d[i][j] = d[i - 1][j] + d[i - 1][j - 1];
				cout << d[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}

//»ý·«