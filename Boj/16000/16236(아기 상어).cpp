#include <bits/stdc++.h>
using namespace std;
struct P {
	int x, y, move = 0;
	bool isok = false;
};
struct cmp {
	bool operator()(const P &u, const P &v){
		if(u.move == v.move) {
			if(u.isok && v.isok) {
				if(u.x == v.x) return u.y > v.y;
				return u.x > v.x;
			} else return u.isok < v.isok;
		}
		return u.move > v.move;
	}
};
P shk, pos;
int n, d[21][21], dx[]{-1,0,0,1}, dy[]{0,-1,1,0}, fish[7];
int possible, sz = 2, up = 2, ans;
int visit[21][21];
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}
int sol(struct P &p) {
	memset(visit, false, sizeof(visit));
	visit[p.x][p.y] = true;
	priority_queue<P, vector<P>, cmp> PQ;
	PQ.push(p);
	while(!PQ.empty()) {
		pos = PQ.top();
		PQ.pop();
		if(pos.isok) {
			possible--;
			fish[d[pos.x][pos.y]]--;
			d[pos.x][pos.y] = 0;
			p.x = pos.x;
			p.y = pos.y;
			return pos.move;
		}
		for(int i = 0; i < 4; ++i) {
			int nx = pos.x + dx[i];
			int ny = pos.y + dy[i];
			if(safe(nx, ny) && !visit[nx][ny] && d[nx][ny] <= sz) {
				visit[nx][ny] = true;
				if(d[nx][ny] < sz && d[nx][ny]) PQ.push({nx, ny, pos.move + 1, true});
				else PQ.push({nx, ny, pos.move + 1, false});
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			scanf("%d", &d[i][j]);
			if(d[i][j] == 9) {
				shk.x = i;
				shk.y = j;
				d[i][j] = 0;
			}
			fish[d[i][j]]++;
		}
	}
	possible = fish[1];
	while(possible) {
		int ret = sol(shk);
		ans += ret;
		if(!ret) break;
		--up;
		if(!up) {
			if(sz <= 6)	possible += fish[sz];
			up = ++sz;
		}
	}
	printf("%d\n", ans);
}