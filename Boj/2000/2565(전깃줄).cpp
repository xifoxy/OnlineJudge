#include <bits/stdc++.h>
using namespace std;
int d[501], n, L;
int dp[501];
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		d[u] = v;
		L = max(L, max(u,v));
	}

	int ans = 0;
	for(int i = 1; i <= L; ++i) {
		for(int j = i + 1; j <= L; ++j){
			if(d[i] < d[j] && dp[i] >= dp[j]) dp[j]++;
		}
		ans = max(ans, dp[i]);
	}
	printf("%d\n", n - ans);
}

// 설명(LIS, DP)
// 전깃줄이 교차하지 않으면서 최대한 많이 연결되어야 하는 상태를 구해야 한다.
// 잘 살펴보면 알겠지만 LIS와 똑같다.
// 주의해야할건 주어진 N이 범위가 아니라는것과, 전깃줄이 연결되지 않은 부분도 있다는것이다.
// 문제 예제에선 연결된 전깃줄은 8개 이지만 범위는 10까지이다.