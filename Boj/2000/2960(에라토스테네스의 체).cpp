#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
bool check[1001];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 2; i <= n; ++i) {
		for(int j = i; j <= n; j += i) {
			if(!check[j]) ans++, check[j] = true;
			if(m == ans) {
				printf("%d\n", j);
				exit(0);
			}
		}
	}
}

// 설명(Sieve of Eratosthenes)
// AH SAY~ 말하지 않아도 알아요~