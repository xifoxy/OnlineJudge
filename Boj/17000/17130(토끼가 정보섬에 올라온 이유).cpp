#include <bits/stdc++.h>
using namespace std;
struct P {
	int x, y;
}; P pos;
int dp[1001][1001];
char d[1001][1001];
int n, m, dx[]{1,0,-1}, dy[]{1,1,1}, px = -1, py = -1, nx, ny;
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
int sol() {
	int ret = -1;
	//-1로 초기화 하는 이유는 초기 방문이냐? 아니냐를 구분하기 위해서
	memset(dp, -1, sizeof(dp));
	queue<P> Q;
	dp[px][py] = 0;
	Q.push({px,py});
	while(!Q.empty()) {
		pos = Q.front(); Q.pop();
		for(int i = 0; i < 3; ++i) {
			nx = pos.x + dx[i];
			ny = pos.y + dy[i];
			//우선 해당 좌표가 안전한지 확인한다.
			if(safe(nx, ny) && d[nx][ny] != '#') {
				//만약 캐럿이라면 현재 값이 캐럿의 위치보다 크거나 같으면 갱신하고 큐에갱신
				if(d[nx][ny] == 'C' && dp[nx][ny] <= dp[pos.x][pos.y]) {
					dp[nx][ny] = dp[pos.x][pos.y] + 1;
					Q.push({nx,ny});
				//해당칸을 처음 방문하거나, 해당값보다 현재 위치값이 크면 또 갱신
				} else if((dp[nx][ny] != -1 && dp[nx][ny] < dp[pos.x][pos.y]) || dp[nx][ny] == -1) {
					dp[nx][ny] = dp[pos.x][pos.y];
					//해당 위치가 탈출구면 답 갱신
					if(d[nx][ny] == 'O') ret = max(ret, dp[nx][ny]);
					Q.push({nx,ny});
				}
			}
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		//scanf 9백만번의 기억을 떠올려라.
		scanf("%s", &d[i]);

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(d[i][j] == 'R') {
				px = i;
				py = j;
				break;
			}
		}
		if(px != -1) break;
	}
	int ans = sol();
	printf("%d\n", ans);
}

//나는 이 문제를 BFS + DP 로 풀려고 해서 제법 귀찮았다.
//단순 DP로 풀게되면 그냥 전체 탐색 한번이면 해결되지만,
//BFS로 풀게되면 조건을 잘 처리해줘야 한다. 
//아니면 메모리가 폭죽터지듯 펑펑펑~터지거나 답이 안나온다.