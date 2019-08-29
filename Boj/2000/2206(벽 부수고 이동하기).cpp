#include <bits/stdc++.h>
using namespace std;
struct Node{
    int x, y, breaker;
};
const int M = 1e3 + 1;
char board[M][M];
int dp[2][M][M];
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
int n, m;

bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

int bfs(){
    queue<Node> Q;
    dp[0][0][0] = 1;
    Q.push({0,0,0});
    while(!Q.empty()){
        Node current = Q.front();
        Q.pop();
        if(current.x == n - 1 && current.y == m - 1) return dp[current.breaker][current.x][current.y];
        for(int direction = 0; direction < 4; ++direction){
            int nx = current.x + dx[direction];
            int ny = current.y + dy[direction];

            // 벽을 부순 상태를 체크하기위한 변수
            int bk = current.breaker;

            if(safe(nx,ny)){

                // 설명참조
                // 너비 우선 탐색 특성상 해당 좌표 방문 여부만 체크하면 되기 때문에
                // 초기 배열의 상태를 시작점을 제외하고는 0으로 놔둔다.
                if(board[nx][ny] == '1' && bk == 0 && !dp[bk + 1][nx][ny]){
                    Q.push({nx,ny,bk + 1});
                    dp[bk + 1][nx][ny] = dp[bk][current.x][current.y] + 1;
                } else if(board[nx][ny] == '0' && !dp[bk][nx][ny]){
                    Q.push({nx,ny,bk});
                    dp[bk][nx][ny] = dp[bk][current.x][current.y] + 1;
                }
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d%d", &n, &m);

    // 속도를 높이기 위해서는 %1d보단 문자열로 입력받아 파싱하는게 좋다.
    for(int i = 0; i < n; ++i)
        scanf("%s", board[i]);

    printf("%d\n", bfs());
}

// 설명(BFS, DP)
// 길 찾기 문제인데, "벽을 하나 부술 수 있다" 라는 전제 조건이 붙는다.
// 그렇다면 메모이제이션을 활용할때 벽을 부쉈을때와, 벽을 부수지 않았을때 두 가지의 경우를 놓고
// 메모를 해나가면 최단거리를 뽑을 수 있다.

// 잘 생각해보면 부숴야 갈 수 있는 최단거리가 다르더라도 너비우선 탐색이라는 제한덕에
// 최적해가 아닌건 자연스레 걸러지게 되어 있다.