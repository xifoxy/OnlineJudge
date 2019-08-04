#include <bits/stdc++.h>
using namespace std;
const int M = 1299710;
int tc;
bool isprime[M];
vector<int> prime;
int main() {
	for(int i = 2; i < M; ++i) {
		if(isprime[i] == false) {
			prime.push_back(i);
			for(long long j = 1LL * i * i; j < M; j += i)
				isprime[j] = true;
		}
	}

	scanf("%d", &tc);
	while(tc--) {
		int num, idx;
		scanf("%d", &num);
		for(int i = 0; i < prime.size(); ++i) {
			if(num <= prime[i]) {
				idx = i;
				break;
			}
		}
		if(prime[idx] == num || num <= 3) puts("0");
		else printf("%d\n", prime[idx] - prime[idx - 1]);
	}
}

// 설명(Sieve of Eratosthenes)
// 주어진 숫자가 소수가 아닐 경우 주어진 숫자보다 작은 소수와 큰 소수 사이의 범위를 구한다.