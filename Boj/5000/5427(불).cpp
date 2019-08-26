#include <bits/stdc++.h>
using namespace std;
struct info {
	int x, y;
};
const int M = 1e3 + 1;
char building[M][M];
int dp[M][M];
int width, height, sx, sy;
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < height && y < width && building[x][y] == '.';
}
void fire_fill(queue<info> &Q) {
	while(!Q.empty()) {
		info t = Q.front();
		Q.pop();

		for(int i = 0; i < 4; ++i) {
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];

            //BFS특성상 방문하지 않은 좌표만 갱신하면 된다.
			if(safe(nx, ny) && !dp[nx][ny]) {
				dp[nx][ny] = dp[t.x][t.y] + 1;
				Q.push({nx,ny});
			}
		}
	}
}
int sol() {
	queue<info> Q;
	Q.push({sx,sy});
	dp[sx][sy] = 1;
	while(!Q.empty()) {
		info t = Q.front();
		Q.pop();

        //배열을 벗어나는 경우 탈출가능한 경우이다.
		if(t.x == 0 || t.y == 0 || t.x == height - 1 || t.y == width - 1) return dp[t.x][t.y];

		for(int i = 0; i < 4; ++i) {
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];

            //불이 전혀 없는 경우도 생각 해야 된다. 그러니 !dp[nx][ny]가 필요하다.
            //그리고 아래 설명의 3번 조건을 충족해야된다.
			if(safe(nx, ny) && (!dp[nx][ny] ||dp[nx][ny] > dp[t.x][t.y] + 1)) {
				dp[nx][ny] = dp[t.x][t.y] + 1;
				Q.push({nx,ny});
			}
		}
	}
	return 0;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		memset(dp, 0, sizeof(dp));
		queue<info> Q;
		scanf("%d %d", &width, &height);
		for(int i = 0; i < height; ++i) {
			scanf("%s", building[i]);

            //safe함수의 통일성을 위한 밑작업
			for(int j = 0; j < width; ++j) {
				if(building[i][j] == '@') {
					sx = i, sy = j;
					building[i][j] = '.';
				}

                //불을 먼저 확산시키기 위해서 큐에 좌표를 닮고
                //불의 위치마다 dp배열을 1로 초기화 한다.
				if(building[i][j] == '*') {
					Q.push({i,j});
					dp[i][j] = 1;
					building[i][j] = '.';
				}
			}
		}
		fire_fill(Q);
		int ans = sol();
		if(ans) printf("%d\n", ans);
		else puts("IMPOSSIBLE");
	}
}

// 설명(BFS)
// 예전에 풀었던 방법은 불을 이동시키고 불이 존재하는 지역은 사람이 못가도록 만들었다.
// 이번에 푼 방법은 플러드필을 두개로 쪼갰다.

// 1. 우선 입력 받을때 불과 사람의 위치를 확인하고 전부다 '.'으로 바꾼다.
// 2. 1번이 선행됨으로써 safe함수가 통일성을 갇게 되니 dp배열에서만 비교하면 된다.
// 3-1. 불을 먼저 확산시켜준다.(fire_fill함수)
// 3-2. 그런다음 사람의 위치를 1로 초기화 시켜주고 현재 좌표(Cur) 
//     dp[cur.x][cur.y] + 1보다 더 큰값이 존재하는곳으로만 이동한다.
//     dp[cur.x][cur.y] + 1보다 작거나 같은 값을 가진곳은 불이 먼저 
//     이동할 수 있는 곳이기에 예외로 걸어준다.
// 4. 탈출조건은 주어진 building 배열을 벗어나기만 하면 x,y화 좌표 
//     기준으로 0혹은 (width, height) - 1 이 되는 좌표가 존재할 경우 반환해준다.

// Ps. sol함수에서 조건문에 !dp[nx][ny] 를 추가하지 않아서 한번 틀렸다.
//     불이 없는 경우도 생각해야된다.