#include <bits/stdc++.h>
using namespace std;
long long dp[101][21];
int num[101], n;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &num[i]);
	}


    // 기저(첫번째 숫자)
	dp[1][num[1]] = 1;

	for(int i = 2; i < n; ++i) {
		for(int j = 0; j <= 20; ++j) {
            // 이전 단계 유효 수가 존재할때
            // 유효수 + 새로운숫자 가 20을 넘지 않으면
            // 현재 단계에 더해준다.
			if(dp[i - 1][j] && j + num[i] <= 20) {
				dp[i][j + num[i]] += dp[i - 1][j];
			}

			if(dp[i - 1][j] && j - num[i] >= 0) {
				dp[i][j - num[i]] += dp[i - 1][j];
			}
		}
	}
	printf("%lld\n", dp[n - 1][num[n]]);
}

// 설명(DP)
// 완탐으로 돌리기에는 유효한 숫자가 들어왔아을때 1 << N - 2 만큼 들어오기에 불가능하다.
// 그래서 어떻게 풀지 고민하다가 숫자의 유효범위에 대한 설명을 보고 답을 떠올렸다.
// 계산과정 중에 숫자는 0 <= Num <= 20 을 벗어나면 안된다.
// 그러니 계산상에 유효한 숫자가 존재할때 d[i][유효숫자] 에 더해주는 방식으로 값을 만들어가면 된다.