#include <bits/stdc++.h>
using namespace std;
int d[10001], tc, a;
int d2[10001];
vector<int> isprime;
int main() {
	for(int i = 2; i <= 10000; ++i) {
		if(!d[i]) {
			for(int j = i * i; j <= 10000; j += i)
				d[j] = 1;
			isprime.push_back(i);
		}
	}
	for(int i = 0; i < isprime.size(); ++i) {
		for(int j = i; j < isprime.size(); ++j) {
			if(isprime[i] + isprime[j] > 10000) break;
			int num = isprime[i] + isprime[j];
			d[num] = isprime[i];
			d2[num] = isprime[j];
		}
	}
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &a);
		printf("%d %d\n", d[a], d2[a]);
	}
}

//소수를 구한다, 더한다, 갱신한다. 끝