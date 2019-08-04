#include <bits/stdc++.h>
using namespace std;
int n, a, m, x, y, mov, ans, idx, st;
char direc;
int d[101][101], dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
struct P { int x, y; };
list<P> L;
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n && d[x][y] != 1;
}
int direction() {
	if(idx == 0) return direc == 'D' ? 2 : 3;
	if(idx == 1) return direc == 'D' ? 3 : 2;
	if(idx == 2) return direc == 'D' ? 1 : 0;
	if(idx == 3) return direc == 'D' ? 0 : 1;
}
bool move_fun(int st, int mov) {
	P pos;
	for(int i = st; i < mov; ++i) {
		pos = L.front();
		int nx = pos.x + dx[idx];
		int ny = pos.y + dy[idx];
		++ans;
		if(safe(nx, ny)) {
			L.push_front({nx,ny});
			if(d[nx][ny] != 2) {
				pos = L.back();
				d[pos.x][pos.y] = 0;
				L.pop_back();
			}
			d[nx][ny] = 1;

		} else return true;
	}
	idx = direction();
	return false;
}

int main() {
	scanf("%d%d", &n, &a);
	for(int i = 0; i < a; ++i) {
		scanf("%d%d", &x, &y);
		d[x - 1][y - 1] = 2;
	}
	d[0][0] = 1;
	L.push_front({0,0});
	scanf("%d", &m);
	bool isdead = false;
	for(int i = 0; i < m; ++i) {
		scanf("%d %c", &mov, &direc);
		if(isdead) continue;
		isdead = move_fun(st, mov);
		st = mov;
	}
	if(!isdead) isdead = move_fun(0, 999);
	printf("%d\n", ans);
}

//설명
//나는 어렸을때 못해봤던 뱀 게임이다. 
//이동에 O(1)의 코스트가 들어가는 리스트를 이용했다.
//문제 풀면서 주의 해야 할 점은 주어진 커맨드가 끝났을때 이다.