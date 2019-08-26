#include <bits/stdc++.h>
using namespace std;
const int M = 31;
int dp[M][M], tc, n, r;
int main() {
	for(int i = 0; i < M; ++i)
		dp[i][0] = 1;

	for(int i = 1; i < M; ++i)
		for(int j = 1; j <= i; ++j)
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];

	scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &r, &n);
		printf("%d\n", dp[n][r]);
	}
}

int foo(int n, int r){
    int &ret = dp[n][r];
    if(n == r || r == 0)
        return 1;
    if(ret) return ret;
    return ret = foo(n - 1, r - 1) + foo(n - 1, r);
}


// 난 순열과 조합이 정말 싫다...