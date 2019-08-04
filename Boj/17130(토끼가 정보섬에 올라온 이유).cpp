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
	//-1�� �ʱ�ȭ �ϴ� ������ �ʱ� �湮�̳�? �ƴϳĸ� �����ϱ� ���ؼ�
	memset(dp, -1, sizeof(dp));
	queue<P> Q;
	dp[px][py] = 0;
	Q.push({px,py});
	while(!Q.empty()) {
		pos = Q.front(); Q.pop();
		for(int i = 0; i < 3; ++i) {
			nx = pos.x + dx[i];
			ny = pos.y + dy[i];
			//�켱 �ش� ��ǥ�� �������� Ȯ���Ѵ�.
			if(safe(nx, ny) && d[nx][ny] != '#') {
				//���� ĳ���̶�� ���� ���� ĳ���� ��ġ���� ũ�ų� ������ �����ϰ� ť������
				if(d[nx][ny] == 'C' && dp[nx][ny] <= dp[pos.x][pos.y]) {
					dp[nx][ny] = dp[pos.x][pos.y] + 1;
					Q.push({nx,ny});
				//�ش�ĭ�� ó�� �湮�ϰų�, �ش簪���� ���� ��ġ���� ũ�� �� ����
				} else if((dp[nx][ny] != -1 && dp[nx][ny] < dp[pos.x][pos.y]) || dp[nx][ny] == -1) {
					dp[nx][ny] = dp[pos.x][pos.y];
					//�ش� ��ġ�� Ż�ⱸ�� �� ����
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
		//scanf 9�鸸���� ����� ���÷���.
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

//���� �� ������ BFS + DP �� Ǯ���� �ؼ� ���� �����Ҵ�.
//�ܼ� DP�� Ǯ�ԵǸ� �׳� ��ü Ž�� �ѹ��̸� �ذ������,
//BFS�� Ǯ�ԵǸ� ������ �� ó������� �Ѵ�. 
//�ƴϸ� �޸𸮰� ���������� ������~�����ų� ���� �ȳ��´�.