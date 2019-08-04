#include <bits/stdc++.h>
using namespace std;
int T, n, d[10001];
int main() {
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		cin >> n;
		int avg = 0;
		for(int i = 0; i < n; ++i) {
			cin >> d[i];
			avg += d[i];
		}
		avg /= n;
		int ans = 0;
		for(int i = 0; i < n; ++i) {
			if(d[i] - avg > 0) {
				ans += (d[i] - avg);
			}
		}
		printf("#%d %d\n", tc, ans);
	}
}

//±¸Çö