#include <bits/stdc++.h>
using namespace std;
const int MX = 1000;
int a[MX], n, ans;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);

	ans = a[0];
	for(int i = 1; i < n; ++i) {
		a[i] += a[i - 1];
		ans += a[i];
	}
	printf("%d\n", ans);
}

//설명
//문제가 친절하니 문제를 보자.