#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> bt{
	{0,1,2},
	{3,7,9,11},
	{4,10,14,15},
	{0,4,5,6,7},
	{6,7,8,10,12},
	{0,2,14,15},
	{3,14,15},
	{4,5,7,14,15},
	{1,2,3,4,5},
	{3,4,5,9,13}};
const int INF = 1e7, CL = 16;
int clocks[16];
int sol(int c) {
	int ret = INF;
	if(c == 10) {
		for(int i = 0; i < CL; ++i)
			if(clocks[i] != 12) return ret;
		return 0;
	}

	for(int i = 0; i < 4; ++i) {
		ret = min(ret, i + sol(c + 1));
		for(int j = 0; j < bt[c].size(); ++j) {
			int idx = bt[c][j];
			clocks[idx] += 3;
			if(clocks[idx] > 12) clocks[idx] = 3;
		}
	}
	return ret;
}
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		for(int i = 0; i < CL; ++i)
			scanf("%d", &clocks[i]);

		int ans = sol(0);
		printf("%d\n", ans == INF ? -1 : ans);
	}
}