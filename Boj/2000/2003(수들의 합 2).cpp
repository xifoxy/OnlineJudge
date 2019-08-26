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

//설명
//투포인터의 기본 개념이 필요하다.
//슬라이딩 윈도우, 투포인터 두개다 비슷한 개념이니 숙지해야한다.
