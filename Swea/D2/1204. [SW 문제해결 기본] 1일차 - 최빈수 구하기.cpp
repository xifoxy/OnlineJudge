#include <bits/stdc++.h>
int t, j, i, d[102], a, k;
int main() {
	scanf("%d", &t);
	for(; i < t; ++i) {
		scanf("%d", &k);
		int ans = 0;
		memset(d, 0, sizeof(d));
		for(j = 0; j < 1000; ++j)
			scanf("%d", &a), d[a]++;
		for(j = 0; j <= 100; ++j) {
			ans = d[j] >= d[ans] ? j : ans;
		}
		printf("#%d %d\n", k, ans);
	}
}

//»ý·«