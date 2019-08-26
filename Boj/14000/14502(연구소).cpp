#include <bits/stdc++.h>
using namespace std;
struct P {
	int x, y;
};
int n, m, dx[]{1,-1,0,0}, dy[]{0,0,1,-1}, virus;
queue<P> vi, Q;
P pos;
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
int flood(vector<vector<int>> v) {
	int ret = virus;
	Q = vi;
	while(!Q.empty()) {
		pos = Q.front(); Q.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = pos.x + dx[i];
			int ny = pos.y + dy[i];
			if(safe(nx, ny) && !v[nx][ny]) {
				v[nx][ny] = 2;
				Q.push({nx,ny});
				ret--;
			}
		}
	}
	return ret - 3;
}
int n_per(vector<vector<int>> &v, int x, int y, int wall = 3) {
	if(wall == 0) {
		return flood(v);
	}
	int ret = 0;
	for(int i = x; i < n; ++i) {
		if(i != x) y = 0;
		for(int j = y; j < m; ++j) {
			if(v[i][j] == 0) {
				v[i][j] = 1;
				ret = max(ret, n_per(v, i, j, wall - 1));
				v[i][j] = 0;
			}
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	vector<vector<int>> vec(n, vector<int>(m));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d", &vec[i][j]);
			if(vec[i][j] == 0) virus++;
			if(vec[i][j] == 2) vi.push({i,j});
		}
	}
	printf("%d\n", n_per(vec, 0, 0));
}

//����
//�������� �����ϸ鼭 �ٲ� �������(��Ž���� �����Ѱ�?)
//������ �а� ��Ž���� �ذ� �����Ѱ�? ��� ������� �����°ź��Ͱ�
//�����ذ� �ɷ��� �������� �ַ���� �ð��� �ٿ����� �����̴�.
//���� ������ �� ���� 64���߿� 3���� ����
//�̸��� 64���߿� 3���� �� �� �ִ� ����� �� �̴�.
//������ ������ �׳� �������� ���ϰ� �Ź� Ȯ����Ѻ���ȴ�.