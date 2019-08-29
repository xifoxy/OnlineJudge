#include <bits/stdc++.h>
using namespace std;
const int INF = 9e3;
int n, sum, mn = INF, mx = -INF, cnt;
int d[8080];
int a[500001];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		int idx = a[i] + 4000;
		d[idx]++;
		sum += a[i];
		if(cnt < d[idx])
			cnt = d[idx];

		mn = min(a[i], mn);
		mx = max(a[i], mx);
	}
	sort(a, a + n);
	printf("%d\n", int(floor((float)sum / n + 0.5)));
	printf("%d\n", a[n / 2]);

	int cb;
	bool chk = false;
	for(int i = 0; i <= 8000; ++i) {
		if(d[i] == cnt) {
			cb = i - 4000;
			if(chk) break;
			chk = true;
		}
	}
	printf("%d\n", cb);
	printf("%d\n", abs(mx - mn));
}

// 설명
// 주어진대로 구현하면 된다.