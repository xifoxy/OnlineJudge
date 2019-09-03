#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001], n, m, area;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%1d", &dp[i][j]);
			if(dp[i][j]){
                // 1하나만 주어졌을 경우를 생각해 예외처리를 해야한다.
				area = area ? area : 1;
                // 점화식
				dp[i][j] += min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
				area = max(area, dp[i][j]);
			}
		}
	}
	printf("%d\n", area * area);
}

// 설명(DP)
// 주어진 값을 토대로 가장큰 정사각형을 찾기위한 점화식은 어떻게 되어야 할까?
// 생각외로 간단한데 현재 좌표에서 ←↖↑ 값중 가장 작은값들을 더해가면 된다.