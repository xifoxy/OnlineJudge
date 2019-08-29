#include <bits/stdc++.h>
using namespace std;
const int MX = 10001;
int a[MX], n, m, ans;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	int l = 0, r = 0, sum = 0;
	while(r <= n) {
		if(sum == m) ans++;
		if(sum >= m) sum -= a[l++];
		else sum += a[r++];
	}
	printf("%d\n", ans);
}

// 설명(Two Pointer, Sliding Window)
// 투포인터, 슬라이딩 윈도우 기본 문제이다. 개념 숙지하고 풀면 된다.
