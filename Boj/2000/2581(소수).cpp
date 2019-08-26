#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10000;
int n, m;
unsigned char sieve[(MAX_N + 7) / 8];
inline bool isprime(int x) {
	return sieve[x >> 3] & (1 << (x & 7));
}
inline void setComposite(int x) {
	sieve[x >> 3] &= ~(1 << (x & 7));
}

void eratosthenes() {
	memset(sieve, 255, sizeof(sieve));
	setComposite(0);
	setComposite(1);
	for(int i = 2; i * i <= m; ++i)
		if(isprime(i))
			for(int j = i * i; j <= m; j += i)
				setComposite(j);
}
int main() {
	cin >> n >> m;
	int sum = 0, min_num = 99999;
	eratosthenes();
	for(int i = n; i <= m; ++i) {
		if(isprime(i)) {
			min_num = min(i, min_num);
			sum += i;
		}
	}
	if(sum) cout << sum << '\n' << min_num;
	else cout << -1;
}

//에라토스테네스 비트로 구현하기