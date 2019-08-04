#include <bits/stdc++.h>
using namespace std;
int T, d[100001], n;
int dp[100001];
int main() {
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		cin >> n;
		memset(d, 0, sizeof(d));
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; ++i) cin >> d[i];

		int mx;
		mx = dp[0] = d[0];
		for(int i = 1; i < n; ++i) {
			dp[i] = d[i];
			if(dp[i] + dp[i - 1] > d[i])
				dp[i] += dp[i - 1];

			mx = max(dp[i], mx);
		}
		printf("#%d %d\n", tc, mx);
	}
}

//최대증가수열