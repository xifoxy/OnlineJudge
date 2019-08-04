#include <bits/stdc++.h>
using namespace std;
int t, i, a;
int main() {
	scanf("%d", &t);
	for(; i < t; ++i) {
		int mx = 0;
		for(int j = 0; j < 10; ++j) {
			scanf("%d", &a);
			mx = mx < a ? a : mx;
		}
		printf("#%d %d\n", i + 1, mx);
	}
}

//»ý·«