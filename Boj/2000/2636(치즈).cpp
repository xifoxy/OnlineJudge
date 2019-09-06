#include <bits/stdc++.h>
using namespace std;
const int M = 1e2 + 1;
struct P{
	int x, y;
};
int n, m;
int board[M][M];
int dx[]{1,-1,0,0},dy[]{0,0,1,-1};
bool visit[M][M];
bool safe(int x, int y){
	return x >= 0 && y >= 0 && x < n && y < m;
}
void BFS(queue<P> &ret, int x, int y){
	queue<P> Q;
	Q.push({x,y});
	visit[x][y] = true;

	while(!Q.empty()){
		P p = Q.front();
		Q.pop();

		for(int direction = 0; direction < 4; ++direction){
			int nx = p.x + dx[direction];
			int ny = p.y + dy[direction];
			if(safe(nx,ny) && !visit[nx][ny]){
				visit[nx][ny] = true;
				if(board[nx][ny])
					ret.push({nx,ny});
				else Q.push({nx,ny});
			}
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &board[i][j]);
		}
	}

	queue<P> Q;
	BFS(Q, 0, 0);
	int sz = 0, t = 0;
	for(;!Q.empty(); ++t){
		sz = Q.size();
		
		for(int i = 0; i < sz; ++i){
			P p = Q.front();
			Q.pop();

			for(int direction = 0; direction < 4; ++direction){
				int nx = p.x + dx[direction];
				int ny = p.y + dy[direction];
				if(safe(nx,ny) && !visit[nx][ny]){
					if(!board[nx][ny]) BFS(Q, nx, ny);
					else {
						visit[nx][ny] = true;
						board[nx][ny]--;
						Q.push({nx,ny});
					}
				}
			}
		}
	}
	printf("%d\n%d", t, sz);
}

// ����(BFS)
// �� �������� �����Ұ� ġ����� ������ ġ�� �ܺ��� ������ �� �������� �ƴ°� �ۿ� ����.
// �������� BFS�� �� �̿����ָ� �ȴ�.