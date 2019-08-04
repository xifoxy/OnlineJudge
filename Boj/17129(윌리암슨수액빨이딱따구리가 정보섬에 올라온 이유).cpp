#include <bits/stdc++.h>
using namespace std;
struct P {
	int x, y, cnt;
}; P pos;
int dx[]{0,0,1,-1}, dy[]{1,-1,0,0}, n, m, px = -1, py = -1;
char d[3001][3001];
bool visit[3001][3001];
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
int sol(int x, int y) {
	queue<P> Q;
	visit[x][y] = true;
	Q.push({x,y,1});
	while(!Q.empty()) {
		pos = Q.front(); Q.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = pos.x + dx[i];
			int ny = pos.y + dy[i];
			//1�� ���̴� �湮�Ұ�
			if(safe(nx, ny) && !visit[nx][ny] && d[nx][ny] != '1') {
				//������ 1�� �ɷ����� �ش� ��ġ�� 0�� �ƴ϶�¶��� �������̶�� ���̴�.
				//pos.x, pos.y���� �����ϸ� ������ Ƚ���� ���� �ȴ�.
				if(d[nx][ny] != '0') {
					return pos.cnt;
				}
				//�湮üũ �� ����ĭ�� ���������� ī���� + 1
				visit[nx][ny] = true;
				Q.push({nx,ny,pos.cnt + 1});
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		//1d�� �ްԵǸ� scnaf�� 9�鸸 ���� ��������.
		scanf("%s", &d[i]);
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			//�����Ͽ��� �� ��ǥ���ϴ� Ʈ��
			//���� �����ϴ�.
			if(d[i][j] == '2') {
				px = i, py = j;
				break;
			}
		}
		if(px != -1) break;
	}
	int ans = sol(px, py);
	if(ans) printf("%s\n%d\n", "TAK", ans);
	else puts("NIE");
}

//������ ����� ���� �ʾƼ� ��� Ʋ����, �Է¶����� ��� Ʋ�ȴ� �����̴�.
//������ ���� �ʾ����� �ִܰŸ��� �ƴ� �� �԰ԵǴ����� ���Ѱ� ����ؼ� Ʋ�ȴ�(���� ��û�ߴ�)
//�Է¶����� Ʋ����...�� �̰� ���� ����̴�(scanf("%1d") �̰ɷ� �Է��� 3e3 * 3e3�� �ްԵǸ�...
//�뷫 �뷫 0.5~0.7�ʰ� �ɸ��ٰ� �Ѵ�. �׷��ϱ� 9�鸸�������� ������ ���� ó�Դ°Ŵ�.
//�Է¹޴°� �ذ��ϸ� �������� flood fill������ ġȯ�ȴ�.