#include <bits/stdc++.h>
using namespace std;
int t, n, a, i, j;
int main() {
	scanf("%d", &t);
	for(; i < t; ++i) {
		int mn = 987654321;
		scanf("%d", &a);
		map<int, int> mp;
		for(j = 0; j < a; ++j) {
			scanf("%d", &n);
			n = abs(n);
			mp[n]++;
			mn = min(mn, n);
		}
		printf("#%d %d %d\n", i + 1, mn, mp[mn]);
	}
}

//»ý·«