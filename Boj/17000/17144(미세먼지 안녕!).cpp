#include <bits/stdc++.h>
using namespace std;
int dx[]{1,0,-1,0}, dy[]{0,1,0,-1};
int n, m, t, d[51][51], temp[51][51], nx, ny, devide, idx, h, b;
struct P {
	int x, y;
};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m && d[x][y] != -1;
}
void inhale() {
	idx = 0;
	d[h][0] = d[b][0] = 0;
	for(int i = h; i > 0; --i) d[i][0] = d[i - 1][0];
	for(int i = 0; i < m - 1; ++i) d[0][i] = d[0][i + 1];
	for(int i = 0; i < h; ++i) d[i][m - 1] = d[i + 1][m - 1];
	for(int i = m - 1; i > 1; --i) d[h][i] = d[h][i - 1];
	for(int i = b; i < n - 1; ++i) d[i][0] = d[i + 1][0];
	for(int i = 0; i < m - 1; ++i) d[n - 1][i] = d[n - 1][i + 1];
	for(int i = n - 1; i > b; --i) d[i][m - 1] = d[i - 1][m - 1];
	for(int i = m - 1; i > 1; --i) d[b][i] = d[b][i - 1];
	d[h][0] = d[b][0] = -1;
	d[h][1] = d[b][1] = 0;
}
void spread() {
	memcpy(temp, d, sizeof(temp));
	for(int x = 0; x < n; ++x) {
		for(int y = 0; y < m; ++y) {
			if(d[x][y] >= 5) {
				for(int k = 0; k < 4; ++k) {
					devide = d[x][y] / 5;
					nx = x + dx[k];
					ny = y + dy[k];
					if(safe(nx, ny)) {
						temp[nx][ny] += devide;
						temp[x][y] -= devide;
					}
				}
			}
		}
	}
	memcpy(d, temp, sizeof(temp));
	inhale();
}
int sol() {
	int ret = 0;
	while(t--) spread();

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			ret += d[i][j];
	return ret;
}
int main() {
	scanf("%d%d%d", &n, &m, &t);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d", &d[i][j]);
			if(d[i][j] == -1) {
				h = b = i;
			}
		}
	}
	h--;
	printf("%d\n", sol() + 2);
}

//����
//�� ������ �л�Ǵ� �ý����� �����ϴ°� �߿��ϴ�.
//A��� �����ʵ�� A�� ������ �ʵ� B��
//A�� ���� ������ ������ B�� �����ְ� ���ְ� �ϸ� �ȴ�.