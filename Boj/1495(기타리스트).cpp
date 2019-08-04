#include <bits/stdc++.h>
using namespace std;
bool d[1001][1001];
int main() {
	int n, s, m;
	scanf("%d%d%d", &n, &s, &m);
	d[0][s] = true;

	for(int i = 1; i <= n; ++i) {
		int val;
		scanf("%d", &val);
		for(int j = 0; j <= m; ++j) {
			if(d[i - 1][j]) {
				if(j + val <= m) d[i][j + val] = true;
				if(j - val >= 0) d[i][j - val] = true;
			}
		}
	}
	int ans = -1;
	for(int i = 0; i <= m; ++i) {
		if(d[n][i]) ans = i;
	}
	printf("%d\n", ans);
}