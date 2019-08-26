#include <bits/stdc++.h>
using namespace std;
int n, l, cnt, ans, t;
int main() {
	scanf("%d%d", &n, &l);
	for(ans = 1; cnt < n; ans++) {
		t = ans;
		bool chk = true;
		while(t > 0) {
			if(t % 10 == l) chk = false;
			t /= 10;
		}
		if(chk) cnt++;
	}
	printf("%d\n", ans - 1);
}

// 설명(Brute Force)
// N의 범위가 작다. 그러니 전부다 확인하면서 L이 포함된 숫자를 배제하면된다.