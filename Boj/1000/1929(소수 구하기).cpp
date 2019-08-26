#define _CRT_SECURE_NO_WARNINGS
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORM(i,a,b) for(int i = (a); i > (b); --i)
#define REPM(i,n) FORM(i,n,0)
#define FORS(i,a,b) for(int i = (a); (b[i]); ++i)
#define REPS(i,s) FORS(i,0,s)
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000001;
int n, m;
unsigned char sieve[(MAX_N + 7) / 8];

inline bool isPrime(int k) {
	bool ret = sieve[k >> 3] & (1 << (k & 7));
	return ret;
}

inline void setComposite(int k) {
	sieve[k >> 3] &= ~(1 << (k & 7));
}

void eratosthenes() {
	memset(sieve, 255, sizeof(sieve));

	setComposite(0);
	setComposite(1);

	for(int i = 2; i * i <= n; ++i)
		if(isPrime(i))
			for(int j = i*i; j <= n; j += i)
				setComposite(j);
}


int main() {
	cin >> m >> n;
	eratosthenes();
	for(int i = m; i <= n; i++)
		if(isPrime(i))
			printf("%d\n", i);
}

// 설명(Sieve of Eratosthenes)
// bitdp로 풀었다.