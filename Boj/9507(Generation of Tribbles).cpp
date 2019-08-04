#include <bits/stdc++.h>
using namespace std;
long long dp[68]{1,1,2,4};
int main() {
	for(int i = 4; i <= 69; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}
	int tc, n;
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
}

// 생략