#include <bits/stdc++.h>
using namespace std;
int dx[]{1,-1,0,0,-1,-1,1,1};
int dy[]{0,0,1,-1,-1,1,-1,1};
int mp[51][51], n, m;
bool visit[51][51];
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < m && y < n;
}
void dfs(int x, int y) {
	visit[x][y] = true;
	for(int i = 0; i < 8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(safe(nx, ny) && !visit[nx][ny] && mp[nx][ny]) {
			dfs(nx, ny);
		}
	}
}
int main() {
	while(cin >> n >> m) {
		if(!n && !m) break;
		memset(mp, 0, sizeof(mp));
		memset(visit, false, sizeof(visit));
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				cin >> mp[i][j];

		int ans = 0;
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				if(mp[i][j] && !visit[i][j]) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}

//����
//������ȣ���̱�� ���� flood fill�� ���� ���� �����̴�.
//�� �������� �� �����ؾ� �� ���� ��ǥ�ϳ��� �ȹ�˻��� ����� �����ϸ� �ȴ�.