#include <bits/stdc++.h>
using namespace std;
const int M = 1e2 + 1;
int board[M][M];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n, m;
struct info {
	int x, y;
};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
void flood_fill(int x, int y, queue<info> &ret) {
	queue<info> Q;
	Q.push({x,y});
	board[x][y] = -1;
	while(!Q.empty()) {
		info t = Q.front();
		Q.pop();

		for(int i = 0; i < 4; ++i) {
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			if(safe(nx, ny) && (board[nx][ny] == 0 || board[nx][ny] > 0)) {
				if(board[nx][ny]) {
					board[nx][ny]++;
					if(board[nx][ny] == 3) ret.push({nx,ny});
				} else {
					board[nx][ny] = -1;
					Q.push({nx,ny});
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d", &board[i][j]);

	queue<info> Q;
	flood_fill(0, 0, Q);
	

	int ans = 0;
	while(!Q.empty() && ++ans) {
		int sz = Q.size();
		for(int i = 0; i < sz; ++i) {
			info cur = Q.front();
			Q.pop();

			board[cur.x][cur.y] = -1;
			for(int k = 0; k < 4; ++k) {
				int nx = cur.x + dx[k];
				int ny = cur.y + dy[k];
				if(board[nx][ny] > 0) board[nx][ny]++;
				if(board[nx][ny] == 3) Q.push({nx,ny});
				if(board[nx][ny] == 0) {
					flood_fill(nx, ny, Q);
				}
			}
		}
	}
	printf("%d\n", ans);
}

#include <bits/stdc++.h>
using namespace std;
const int M = 1e2 + 1;
int board[M][M];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n, m;
struct info {
	int x, y;
};
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

// 초기에 치즈와 공기가 닿은 부분 처리 및 내부 공기와 외부공기가 만났을때를 위한 함수
void flood_fill(int x, int y, queue<info> &ret) {
	queue<info> Q;
	Q.push({x,y});
	board[x][y] = -1;
	while(!Q.empty()) {
		info t = Q.front();
		Q.pop();

		for(int i = 0; i < 4; ++i) {
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			if(safe(nx, ny) && (board[nx][ny] == 0 || board[nx][ny] > 0)) {
				if(board[nx][ny]) {
					board[nx][ny]++;
					if(board[nx][ny] == 3) ret.push({nx,ny});
				} else {
					board[nx][ny] = -1;
					Q.push({nx,ny});
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d", &board[i][j]);

	queue<info> Q;
    // 주어진 input값의 테두리는 전부다 공기이다.
	flood_fill(0, 0, Q);
	

    // 아래에서 설명한 3번 및 시간을 체크하기 위해 큐의 사이즈로 반복한다.
	int ans = 0;
	while(!Q.empty() && ++ans) {
		int sz = Q.size();
		for(int i = 0; i < sz; ++i) {
			info cur = Q.front();
			Q.pop();

			board[cur.x][cur.y] = -1;
			for(int k = 0; k < 4; ++k) {
				int nx = cur.x + dx[k];
				int ny = cur.y + dy[k];
				if(board[nx][ny] > 0) board[nx][ny]++;

                // 큐에 중복되게금 쌓이는 값들을 억제해줘야 한다.
				if(board[nx][ny] == 3) Q.push({nx,ny});

                // 외부 공기와 외부 공기가 만났을때 호출
				if(board[nx][ny] == 0) {
					flood_fill(nx, ny, Q);
				}
			}
		}
	}
	printf("%d\n", ans);
}

// 설명(BFS)
// 주어진 치즈에서 공기(0)과 다은 면적이 2이상 이면 그 부위는 녹는다.
// 치즈속에 빈 공간은 외부 공기와 접촉되기 전까지는 공기라고 취급하지 않는다.
// 주어진 공간의 테두리는 무조건 공기이다.

// 위의 설명이 문제에서 주어진 조건인데, 저기서 공기 체크 탐색과 치즈 삭제 파트를
// 따로 나눠서 풀었다.

// 1. input값이 주어지면 치즈 외곽의 공기를 전부다 - 1로 만들어 주되 치즈와 닿은 면적은
// + 1 해준다.(flood_fill함수 에서 일어나는 일)

// ex) 
// 0 0 0 0		-1 -1 -1 -1
// 0 1 1 0 ==>  -1  3  3 -1
// 0 1 0 0 ==>  -1  4 -1 -1
// 0 0 0 0		-1 -1 -1 -1

// 2. 그러면 녹아야 하는 부위는 어떤 방법으로 체크 해줘야 할까 ? 처음에는 2보다 큰 경우
// 에 큐에 담아줬었는데 중복되는 좌표가 너무 많이 잡히더라.그래서 해당 좌표의 값이 3이
// 될때에만 큐에 담아줬다.

// 3. 내부 공기가 외부 공기와 닿은 경우는 어떻게 처리를 해줘야할까?
//     방법은 치즈를 처리한는 큐에서 미리 사이즈를 받아 큐의 사이즈 단위로 반복문을
//     돌면 해결이 된다.
//     첫스택(8, 처리도중 flood_fill호출) -> 두번째 스택(11) -> 세번째 스택(2)
// ex)
// 0 0 0 0 0 0 0 0 0	  -1 -1 -1 -1 -1 -1 -1 -1 -1	 -1 -1 -1 -1 -1 -1 -1 -1 -1  
// 0 0 0 0 0 0 0 0 0	  -1 -1 -1 -1 -1 -1 -1 -1 -1	 -1 -1 -1 -1 -1 -1 -1 -1 -1
// 0 1 1 0 0 0 1 1 0	  -1 [3][3]-1 -1 -1 [3][3]-1	 -1 -1 -1 -1 -1 -1 -1 -1 -1
// 0 1 0 1 1 1 0 1 0 ==>  -1  2  0  2  2  2  0  2 -1 ==> -1 [4]-1 [4] 2 [4]-1 [4]-1
// 0 1 0 0 1 0 0 1 0 ==>  -1  2  0  0  1  0  0  2 -1 ==> -1 [3]-1 -1 [3]-1 -1 [3]-1
// 0 1 0 1 1 1 0 1 0	  -1  2  0  2  2  2  0  2 -1	 -1 [4]-1 [4] 2 [4]-1 [4]-1
// 0 1 1 0 0 0 1 1 0	  -1 [3][3]-1 -1 -1 [3][3]-1	 -1 -1 -1 -1 -1 -1 -1 -1 -1
// 0 0 0 0 0 0 0 0 0	  -1 -1 -1 -1 -1 -1 -1 -1 -1	 -1 -1 -1 -1 -1 -1 -1 -1 -1

// 	  -1 -1 -1 -1 -1 -1 -1 -1 -1
// 	  -1 -1 -1 -1 -1 -1 -1 -1 -1
// 	  -1 -1 -1 -1 -1 -1 -1 -1 -1
//==> -1 -1 -1 -1 [5]-1 -1 -1 -1
//==> -1 -1 -1 -1 -1 -1 -1 -1 -1
// 	  -1 -1 -1 -1 [5]-1 -1 -1 -1
// 	  -1 -1 -1 -1 -1 -1 -1 -1 -1
// 	  -1 -1 -1 -1 -1 -1 -1 -1 -1