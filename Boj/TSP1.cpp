#include <bits/stdc++.h>
double cost[10][10];
bool visit[10];
int n, tc;
double sol(int pos, double ret, int move_cnt, double cst) {
	if(!move_cnt) return std::min(ret, cst);
	for(int i = 0; i < n; ++i) {
		if(!visit[i]) {
			visit[i] = true;
			cst += cost[pos][i];
			ret = sol(i, ret, move_cnt - 1, cst);
			cst -= cost[pos][i];
			visit[i] = false;
		}
	}
	return ret;
}
int main() {
	scanf("%d", &tc); while(tc--) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j)
				scanf("%lf", &cost[i][j]);
		}
		double ans = 987654321;
		for(int i = 0; i < n; ++i) {
			visit[i] = true;
			ans = std::min(ans, sol(i, 987654321, n - 1, 0));
			visit[i] = false;
		}
		printf("%.10lf\n", ans);
	}
}