#include <bits/stdc++.h>
using namespace std;
int tc;
int main() {
	cin >> tc;
	while(tc--) {
		int n, ans;
		int dp[101] = {0,};
		scanf("%d", &n);
		ans = n;
		for(int i = 1; i <= n; ++i) {
			for(int j = i; j <= n; j += i) {
				ans += dp[j] ? 1 : -1;
				dp[j] = dp[j] ? 0 : 1;
			}
		}
		printf("%d\n", n - ans);
	}
}

// 생략