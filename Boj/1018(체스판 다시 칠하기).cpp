#include <bits/stdc++.h>
using namespace std;
char mp[55][55];
int n, m;
int sol(int x, int y) {
	int ret = 0;
	for(int i = x; i < x + 8; ++i) {
		for(int j = y; j < y + 8; ++j) {
			if((i + j) % 2 == 0 && mp[i][j] != 'W') ret++;
			if((i + j) % 2 && mp[i][j] != 'B') ret++;
		}
	}
	return min(ret, 64 - ret);
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%s", mp[i]);
	int ans = 128;
	for(int i = 0; i < n - 7; ++i) {
		for(int j = 0; j < m - 7; ++j) {
			ans = min(ans, sol(i, j));
		}
	}
	printf("%d\n", ans);
}

// 설명(Brute Force)
// 주어진 배열에서 8*8만큼씩 전부다 탐색하면 된다.
