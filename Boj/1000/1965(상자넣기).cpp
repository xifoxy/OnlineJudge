#include <bits/stdc++.h>
using namespace std;
int n, a[1001], dp[1001], ans = 1;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		dp[i] = 1;
	}
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(a[i] < a[j]) {
				dp[j] = max(dp[i] + 1, dp[j]);
				ans = max(ans, dp[j]);
			}
		}
	}
	printf("%d\n", ans);
}

//최장수열이다. 복습겸...