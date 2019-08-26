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

// ����(DP)
// �־��� ���Ĵ�� �޸������̼� ���ָ� �ȴ�.
// �Է��� ������ ũ�ϱ� BST������ �迭ó�� �����ϱ� ���� map�� �̿��ߴ�.