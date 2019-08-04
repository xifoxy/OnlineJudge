#include <bits/stdc++.h>
using namespace std;
int T, a, n;
int main() {
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		cin >> n;
		int sum = 0;
		for(int i = 1; i <= n; ++i) {
			if(i % 2) sum += i;
			else sum -= i;
		}
		printf("#%d %d\n", tc, sum);
	}
}

//»ý·«