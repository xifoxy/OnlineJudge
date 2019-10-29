#include <bits/stdc++.h>
using namespace std;
struct info { int x, y; };
const int M = 51;

// 사방탐색을 위한 좌표
const int dx[]{1,-1,0,0};
const int dy[]{0,0,1,-1};
int dp[M][M];
char board[M][M];
int n;

// 좌표 안전성 체크
bool safe(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}
int sol(){
    int &ret = dp[n-1][n-1];
    // 방문 여부를 위해 초기화
    memset(dp, -1, sizeof(dp));
    queue<info> Q;

    Q.push({0,0});
    dp[0][0] = 0;

    while(!Q.empty()){
        info t = Q.front();
        Q.pop();
        
        // 도착했으면 더이상 탐색할 필요 없다.
        if(t.x == n - 1 && t.y == n - 1) continue;

        // 사방탐색
        for(int direc = 0; direc < 4; ++direc){
            int nx = t.x + dx[direc];
            int ny = t.y + dy[direc];
            if(safe(nx,ny)){
                // 방문하지 않았거나, 현재 위치보다 큰 값이면 갱신
                
                // 흰블럭
                if(board[nx][ny] == '1' && (dp[nx][ny] == -1 || dp[t.x][t.y] < dp[nx][ny])) {
                    dp[nx][ny] = dp[t.x][t.y];
                    Q.push({nx,ny});
                // 검은블럭
                } else if(board[nx][ny] == '0' && dp[nx][ny] == -1 || dp[t.x][t.y] + 1 < dp[nx][ny]) {
                    dp[nx][ny] = dp[t.x][t.y] + 1;
                    Q.push({nx,ny});
                }
            }
        }
    }
    return ret;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%s", board[i]);
    printf("%d\n", sol());
}

// 설명(BFS)
// 처음에 3차원 메모 테이블을 만들어 풀고 최적화를 했다.(3차원으로 하면 갱신주기가 더 많아진다)
// 핵심은 [X,Y] 좌표로 갈때 부셔야 하는 최소한의 블럭이기 때문에
// 메모 테이블에 방문 여부를 확인해가면서 최솟값을 갱신해 나가면 된다.