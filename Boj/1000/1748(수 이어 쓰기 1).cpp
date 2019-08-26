#include <bits/stdc++.h>
using namespace std;
int n, ans, t = 9, cnt;
int main() {
	scanf("%d", &n);
	while(n > 0 && ++cnt) {
		ans += n - t < 0 ? (n * cnt) : (t * cnt);
		n -= t;
		t *= 10;
	}
	printf("%d\n", ans);
}

// Ό³Έν
// 1~9 = 9
// 10~99 = 90
// 100~999 = 900
// 1000~9999 = 9000