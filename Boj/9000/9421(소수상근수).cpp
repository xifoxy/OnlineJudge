#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 1;
int dp[M], n;
int calc(int x) {
	int sum = 0;
	while(x) {
		sum += ((x % 10) * (x % 10));
		x /= 10;
	}
	return sum;
}
int sol(int x) {
	if(dp[x] != M) return dp[x];
	dp[x] = 1;
	return dp[x] = sol(calc(x));
}
int main() {
	vector<int> isprime;
	for(int i = 2; i < M; ++i) {
		if(!dp[i]) isprime.push_back(i);
		for(long long j = 1LL * i * i; j < M; j += i) {
			dp[j] = 1;
		}
	}
	fill(&dp[0], &dp[M], M);

	int n;
	scanf("%d", &n);

	dp[1] = 0;
	for(int i = 0; i < isprime.size(); ++i) {
		if(isprime[i] > n) break;
		int ans = sol(isprime[i]);
		if(!ans) printf("%d\n", isprime[i]);
	}
}

// 설명(Sieve of Eratosthenes)
// 1. 우선 에라토스테네스의 체를 구하는 방법을 알아야 한다.
// 2. 주의해야 할 점은 10 <= N <= 1e6 즉, N제곱이 int의 범위를 벗어날 수 있다.
// 3. 소수를 구할때 썼던 배열을 재활용하여 재귀적으로 해결했다.