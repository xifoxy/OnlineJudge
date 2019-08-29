#include <bits/stdc++.h>
using namespace std;
int dp[680000];
int n, sum;
int main() {
	scanf("%d", &n);
	dp[1] = sum = 1;
	if(n == 1) puts("1");
	else for(int i = 2; i <= n; ++i) {
		sum += (dp[i] = 1 + dp[i - dp[dp[i - 1]]]);
		if(sum >= n) {
			printf("%d\n", i);
			break;
		}
	}
}

// 설명(Math)
// 골롱수열 찾아봐야 한다. 이거 안찾아보고 풀면 Boj에서 공부하고 있을 이유가 없다.