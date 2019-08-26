#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll> dp;
ll n;
int P, Q;
ll sol(ll N) {
	if(dp[N]) return dp[N];
	dp[N] += sol(N / P) + sol(N / Q);
	return dp[N];
}
int main() {
	dp[0] = 1;
	scanf("%lld%d%d", &n, &P, &Q);
	printf("%lld\n", sol(n));
}

// 설명(DP)
// 주어진 공식대로 메모이제이션 해주면 된다.
// 입력의 범위가 크니까 BST이지만 배열처럼 접근하기 쉬운 map을 이용했다.