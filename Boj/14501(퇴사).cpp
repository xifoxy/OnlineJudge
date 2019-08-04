#include <bits/stdc++.h>
using namespace std;
int dp[17], d[17], c[17], n;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d %d", d + i, c + i);
	}

	for(int i = n; i > 0; --i) {
		int next = i + d[i];
		if(next > n + 1) dp[i] = dp[i + 1];
		else dp[i] = max(dp[i + 1], dp[next] + c[i]);
	}
	printf("%d\n", dp[1]);
}

//설명
//풀어본 삼성기출 중에 유일한 DP문제다.
//완탐으로도 가능하지만 우아하게 풀어야 하니까 DP로 풀었다.
//처음 문제를 접했을때 빠른 날짜부터 푸니까 DP식이 떠오르지 않아 고민좀 했다.
//결론은 뒤에서부터 풀면 답이 깔끔하게 나온다.