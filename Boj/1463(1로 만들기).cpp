#include <bits/stdc++.h>
using namespace std;
int d[1000001], n;
int main() {
	scanf("%d", &n);
	d[2] = d[3] = 1;
	for(int i = 4; i <= n; ++i) {
		d[i] = d[i - 1] + 1;
		if(i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
		if(i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
	}
	printf("%d\n", d[n]);
}

// 설명(DP)
// N부터 구해내려 가는 방법과 1부터 구해 올라가는 방법이 있다.
// 편한대로 구현하면 된다.