#include <bits/stdc++.h>
using namespace std;
struct Node{
	int x, y;
};
const int M = 3e3 + 1;
int n, m, s_x = -1, s_y;
char board[M][M];
int dp[M][M];

int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};

bool safe(int x, int y){
	return x >= 0 && y >= 0 && x < n && y < m && board[x][y] != '1';
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; ++i){
		scanf("%s", board[i]);
		for(int j = 0; j < m && s_x == -1; ++j){
			// 시작지점의 좌표를 체크하기 위한 탐색문이다.
			// 시작 좌표가 -1이면 '2'를 만날때까지 입력이 들어올대마다 탐색한다.
			if(board[i][j] == '2'){
				// 시작점의 좌표만 있으면 되기 때문에 0으로 초기화
				board[i][j] = '0';
				s_x = i;
				s_y = j;
			}
		}
	}
	

	// ans를 -1로 초기화 해두면 답을 위한 플래그로도 이용가능하다.
	// dp배열에서 시작점은 1로 초기화 해둔다. 이유는 아래에 있다.
	int ans = -1;
	dp[s_x][s_y] = 1;
	queue<Node> Q;
	Q.push({s_x,s_y});
	while(!Q.empty()){
		Node cur = Q.front();
		Q.pop();

		// 너비우선 탐색 특성상 가장 먼저 만나는 좌표가 답이 된다.(3,4,5 중에서)
		if(board[cur.x][cur.y] > '1'){
			ans = dp[cur.x][cur.y] - 1;
			break;
		}

		for(int direction = 0; direction < 4; ++direction){
			int nx = cur.x + dx[direction];
			int ny = cur.y + dy[direction];

			// 방문하지 않은곳만 방문하면 된다.(dp배열은 0으로 초기화 됨)
			if(safe(nx,ny) && !dp[nx][ny]){
				dp[nx][ny] = dp[cur.x][cur.y] + 1;
				Q.push({nx,ny});
			}
		}
	}

	if(ans == -1) puts("NIE");
	else printf("TAK\n%d\n", ans);
}

// 설명(BFS)
// 너비탐색을 이용해 최단거리를 찾는 문제이다.
// 시간 초과를 한번 경험 했었는데 이유는 각 좌표당 값들을 하나씩 받았기 때문이다.
// flood fill만 잘 이용할줄 안다면 어렵지 않으니 차근히 생각해보면 된다.