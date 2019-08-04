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

//이런거 못풀면 손목 잘라야된다.