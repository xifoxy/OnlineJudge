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
			//1은 벽이니 방문불가
			if(safe(nx, ny) && !visit[nx][ny] && d[nx][ny] != '1') {
				//위에서 1은 걸렀으니 해당 위치가 0이 아니라는뜻은 음식점이라는 뜻이다.
				//pos.x, pos.y까지 도달하며 움직인 횟수가 답이 된다.
				if(d[nx][ny] != '0') {
					return pos.cnt;
				}
				//방문체크 및 현재칸에 도달했으니 카운팅 + 1
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
		//1d로 받게되면 scnaf가 9백만 들어간다 주의하자.
		scanf("%s", &d[i]);
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			//종만북에서 본 좌표구하는 트릭
			//나름 참신하다.
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

//문제를 제대로 읽지 않아서 몇번 틀리고, 입력때문에 몇번 틀렸던 문제이다.
//문제를 읽지 않았을땐 최단거리가 아닌 뭘 먹게되는지에 대한걸 출력해서 틀렸다(정말 멍청했다)
//입력때문에 틀린건...아 이건 제법 충격이다(scanf("%1d") 이걸로 입력을 3e3 * 3e3을 받게되면...
//대략 대략 0.5~0.7초가 걸린다고 한다. 그러니까 9백만번주제에 저렇게 많이 처먹는거다.
//입력받는걸 해결하면 전형적인 flood fill문제로 치환된다.