#include <bits/stdc++.h>
using namespace std;
int T, n;
int d[1000001];
int main() {
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		cin >> n;
		for(int i = 0; i < n; ++i)
			cin >> d[i];

		long long ans = 0;
		int mx = 0;
		for(int i = n - 1; i >= 0; --i) {
			if(mx > d[i])
				ans += mx - d[i];
			else mx = d[i];
		}
		printf("#%d %lld\n", tc, ans);
	}
}