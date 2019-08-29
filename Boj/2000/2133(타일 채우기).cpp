#include <bits/stdc++.h>
using namespace std;
int d[31], n, i, j;
int main() {
	scanf("%d", &n); d[0] = 1;
	for(i = 2; i <= n; i += 2) {
		d[i] = d[i - 2] * 3;
		for(j = i - 4; j >= 0; j -= 2)
			d[i] += d[j] * 2;
	}
	printf("%d\n", d[n]);
}

// 설명(DP)
// 봐도봐도 어렵다 이건
// 거지같은 문제다.