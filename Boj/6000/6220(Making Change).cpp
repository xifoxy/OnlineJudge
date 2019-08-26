#include <bits/stdc++.h>
using namespace std;
const int INF = 1e4;
int C, N, d[11], dp[1001];
int main() {
	cin >> C >> N;
	for(int i = 0; i < N; ++i)
		cin >> d[i];

	sort(d, d + N);
	for(int i = 1; i <= C; ++i) {
		dp[i] = INF;
		for(int j = 0; j < N; ++j) {
			int bef = i - d[j];
			if(bef >= 0 && dp[bef] != INF)
				dp[i] = min(dp[i], dp[bef] + 1);
		}
	}
	printf("%d\n", dp[C]);
}

//원문이 기억이 안난다... 하지만 쉬우니 패스