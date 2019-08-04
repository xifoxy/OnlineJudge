#include <bits/stdc++.h>
using namespace std;
int n, c;
int main() {
	cin >> c;
	for(int tc = 0; tc < c; ++tc) {
		bool v[10]{0,};
		cin >> n;
		printf("Case #%d: ", tc + 1);
		if(!n) puts("INSOMNIA");
		else {
			int v_cnt = 10, i = 0, t;
			while(v_cnt && ++i) {
				int t = n * i;
				while(t) {
					if(!v[t % 10]) {
						v_cnt--;
						v[t % 10] = true;
					}
					t /= 10;
				}
			}
			printf("%lld\n", n * i);
		}
	}
}

// 설명
// INSOMNIA가 나오는 경우는 0밖에 없다.