#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e7 + 1;
int prime[M], sz;
bool isprime[M];
int main() {
	ll s, e;
	scanf("%lld%lld", &s, &e);
	for(ll i = 2; i * i <= e; ++i) {
		if(!isprime[i]) {
			prime[sz++] = i;
			for(ll j = i + i; j * j <= e; j += i)
				isprime[j] = true;
		}
	}
	int ans = 0;
	for(int i = 0; i < sz; ++i) {
		ll n = prime[i];
		while(prime[i] <= e / n) {
			if(prime[i] * n >= s) ans++;
			n *= prime[i];
		}
	}
	printf("%d\n", ans);
}

// 설명(Sieve of Eratosthenes)
// 1016제곱 ㄴㄴ수와 유사한 체를 이용해야 한다.
// 최대 범위가 1e14이니 1e7만큼 돌면서 체를 걸러내면 된다.
// 소수를 구한 후 소수의 제곱에는 중복이 없다는 원리를 이용해서 답을 구하면 된다.