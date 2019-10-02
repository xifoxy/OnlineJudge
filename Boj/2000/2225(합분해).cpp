#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9;
int dp[202][202];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);

    // 숫자 하나로 만들 수 있는 경우의 수
	for(int i = 0; i <= n; ++i) {
		dp[1][i] = 1;
	}
	
	for(int i = 2; i <= k; ++i) {
		for(int j = 0; j <= n; ++j) {
			for(int l = 0; l <= n; ++l) {
                // 숫자 i - 1개를 써서 만든 j라는 숫자가 존재할때
                // j + l 이 n보다 작으면 갱신한다.
				if(dp[i - 1][j] && j + l <= n) {
					dp[i][j + l] = (dp[i][j + l] + dp[i - 1][j]) % MOD;
				}
			}
		}
	}
	printf("%d\n", dp[k][n]);
}


#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9;
int dp[202][202];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
    
	for(int i = 0; i <= n; ++i) {
		dp[1][i] = 1;
	}
	for(int i = 2; i <= k; ++i) {
		dp[i][0] = 1;
		for(int j = 1; j <= n; ++j) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	printf("%d\n", dp[k][n]);
}

// 설명(DP)
// 첫 번째 소스는 나이브한 소스다.
// 두 번째 소스는 최적화를 했다.
// 풀어서 답을 보면 알겠지만 답의 형태는 계차수열의 형태로 만들어진다.