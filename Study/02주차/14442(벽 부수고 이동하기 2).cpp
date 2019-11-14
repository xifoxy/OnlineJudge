#include <bits/stdc++.h>
using namespace std;

struct info{
    int x, y, b;
};

const int M = 1e3+1;
char board[M][M];
int dp[M][M][11];

int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};

int n, m, k;

bool safe(int x, int y){
    return min(x,y) >= 0 && x < n && y < m;
}

int bfs(){
    queue<info> Q;
    Q.push({0, 0, 0});
    dp[0][0][0] = 1;

    while(!Q.empty()){
        info t = Q.front();
        Q.pop();

        if(t.x == n - 1 && t.y == m - 1){
            return dp[t.x][t.y][t.b];
        }

        for(int direction = 0; direction < 4; ++direction){
            int nx = t.x + dx[direction];
            int ny = t.y + dy[direction];
            int bk = t.b;
            if(safe(nx,ny)){
                if(board[nx][ny] == '0' && dp[nx][ny][t.b] == -1){
                    Q.push({nx, ny, bk});
                    dp[nx][ny][bk] = dp[t.x][t.y][t.b] + 1;
                }
                if(board[nx][ny] == '1' && bk < k && dp[nx][ny][t.b + 1] == -1){
                    dp[nx][ny][bk + 1] = dp[t.x][t.y][t.b] + 1;
                    Q.push({nx, ny, bk + 1});
                }
            }
        }
    }


    return -1;
}

int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d%d%d", &n, &m, &k);

    for(int i = 0; i < n; ++i){
        scanf("%s", &board[i]);
    }

    printf("%d\n", bfs());
}

// 설명
// 벽 부수고 이동하기, 말이 되고픈 원숭이와 다를게 없는 문제다.