#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 1;
int dp[M];
int n;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &dp[i]);
	}

	int ans = 0;
	for(int i = 0; i < n - 1; ++i){
		for(int j = i + 1; j < n; ++j){
			if(dp[j] > dp[j-1]){
				ans = max(ans, dp[j] - dp[i]);
			} else break;
		}
	}
	printf("%d\n", ans);
}

// 설명(Brute Force)
// 배열에서 연속된 (등)차수열이 존재할때 a[n] - a[i] 값이 최대가 되는 값을 구해주면 된다.