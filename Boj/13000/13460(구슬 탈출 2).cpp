#include <bits/stdc++.h>
using namespace std;
struct P {
	int bx, by, rx, ry, cnt = 0;
};
int n, m, dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
char f[12][12];
void B_move(struct P &p, int x, int y) {
	while(f[p.bx + x][p.by + y] != '#') {
		p.bx += x;
		p.by += y;
		if(f[p.bx][p.by] == 'O') {
			p.cnt = -1;
			return;
		}
		if(p.bx == p.rx && p.by == p.ry) {
			p.bx -= x;
			p.by -= y;
			return;
		}
	}
}
bool R_move(struct P &p, int x, int y) {
	bool check = true;
	while(f[p.rx + x][p.ry + y] != '#') {
		if(p.rx + x == p.bx && p.ry + y == p.by) {
			if(check) {
				B_move(p, x, y);
				check = false;
			} else break;
			continue;
		}
		p.rx += x;
		p.ry += y;
		if(f[p.rx][p.ry] == 'O') break;
	}
	B_move(p, x, y);
	return p.cnt == -1 ? 0 : 1;
}
int sol(struct P B) {
	int ret = 11;
	queue<P> Q;
	Q.push(B);
	P p;
	while(!Q.empty()) {
		B = Q.front(); Q.pop();
		if(B.cnt == 10) break;
		for(int i = 0; i < 4; ++i) {
			p = B;
			if((f[p.bx + dx[i]][p.by + dy[i]] == '#' && f[p.rx + dx[i]][p.ry + dy[i]] == '#') ||
				(f[p.bx + dx[i]][p.by + dy[i]] == '#' && p.rx + dx[i] == B.bx && p.ry + dy[i] == B.by) ||
				(f[p.rx + dx[i]][p.ry + dy[i]] == '#' && p.bx + dx[i] == B.rx && p.by + dy[i] == B.ry)) continue;
			if(R_move(p, dx[i], dy[i])) p.cnt++;
			if(f[p.rx][p.ry] == 'O' && p.cnt != -1 && p.cnt <= 10) {
				ret = min(p.cnt, ret);
			} else if(f[p.rx][p.ry] != 'O' && p.cnt != -1)
				Q.push(p);

		}
	}
	return ret == 11 ? -1 : ret;
}
int main() {
	P B;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf(" %c", &f[i][j]);
			if(f[i][j] == 'B') {
				B.bx = i;
				B.by = j;
			}
			if(f[i][j] == 'R') {
				B.rx = i;
				B.ry = j;
			}
		}
	}
	int ans = sol(B);
	printf("%d\n", ans);
}

//����
//�Ｚ ������ �˴� ��Ž/�ù� �̴�. �ù� ������ ������ ������, ���� ������ ���� ¥������.
//�ٸ� ������ ��� Ǯ������ �𸣰����� ���� �׻� ���� ������ ���� �����̰� �Ķ�������
//�浹�� ���� ��� �Ķ������� �����̵��� �ۼ��ߴ�.
//�׸��� ���ҳ� ����, ����, ����, ����
//10���ϴ� 10�� �����̶�°� �������.
