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

// ����(Sieve of Eratosthenes)
// 1016���� �������� ������ ü�� �̿��ؾ� �Ѵ�.
// �ִ� ������ 1e14�̴� 1e7��ŭ ���鼭 ü�� �ɷ����� �ȴ�.
// �Ҽ��� ���� �� �Ҽ��� �������� �ߺ��� ���ٴ� ������ �̿��ؼ� ���� ���ϸ� �ȴ�.