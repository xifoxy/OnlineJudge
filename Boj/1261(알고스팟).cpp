#include <bits/stdc++.h>
using namespace std;
struct P {
	int x, y;
};
const int MX = 101;
int a[MX][MX], n, m;
int d[MX][MX], dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
int main() {
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%1d", &a[i][j]);
			d[i][j] = MX * MX;
		}
	}
	queue<P> Q;
	Q.push({0,0});
	d[0][0] = 0;
	while(!Q.empty()) {
		P t = Q.front(); Q.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			if(safe(nx, ny)) {
				if(a[nx][ny] && d[nx][ny] > d[t.x][t.y] + 1) {
					d[nx][ny] = d[t.x][t.y] + 1;
					Q.push({nx,ny});
				}
				if(!a[nx][ny] && d[nx][ny] > d[t.x][t.y]) {
					d[nx][ny] = d[t.x][t.y];
					Q.push({nx,ny});
				}
			}
		}
	}
	printf("%d\n", d[n - 1][m - 1]);
}


// ����(BFS)
// �ʺ�켱 Ž���� Ư���� ���� �Ѵٸ� ���� ����� ������ �ƴϴ�.
// �޸������̼��� �迭�� ����� ū ���� �ʱ�ȭ�� �� ���� ��ġ�� ������ ū�͵鸸 �����ϸ� �ȴ�.