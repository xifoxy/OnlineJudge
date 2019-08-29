#include <bits/stdc++.h>
using namespace std;
int n, num;
int main() {
	bool ans = false;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		num = i;
		int t = i;
		while(t > 0) {
			num += (t % 10);
			t /= 10;
		}
		if(num == n) {
			num = i;
			ans = true;
			break;
		}
	}
	if(ans) printf("%d\n", num);
	else puts("0");
}

// 설명
// 문제에서 주어진 공식대로 구현하면된다.
// N <= 1e6 이기 때문에 완탐으로 해결가능한 부분이다.