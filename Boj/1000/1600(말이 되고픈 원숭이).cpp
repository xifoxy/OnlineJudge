#include <bits/stdc++.h>
using namespace std;

struct info{
    int x, y, cnt;
};

const int M = 2e2+1;

int ddx[]{-1,-2,-2,-1,1,2,2,1};
int ddy[]{-2,-1,1,2,-2,-1,1,2};
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};

int board[M][M];
int dp[M][M][31];
int w, h, jump;
bool safe(int x, int y){
    return min(x,y) >= 0 && x < h && y < w && !board[x][y];
}

queue<info> Q;
int bfs(){
    Q.push({0,0,0});
    dp[0][0][0] = 0;

    while(!Q.empty()){
        info t = Q.front();
        Q.pop();

        if(t.x == h - 1 && t.y == w - 1)
            return dp[t.x][t.y][t.cnt];

        // 점프 할수 있는 횟수가 존재하고,
        // 점프 할 수 있으면 점프한다.
        for(int direction = 0; direction < 8 && t.cnt < jump; ++direction){
            int nx = t.x + ddx[direction];
            int ny = t.y + ddy[direction];
            if(safe(nx, ny) && dp[nx][ny][t.cnt + 1] == -1 && !board[nx][ny]){
                dp[nx][ny][t.cnt + 1] = dp[t.x][t.y][t.cnt] + 1;
                Q.push({nx, ny, t.cnt + 1});
            }
        }
        
        // 사방탐색
        for(int direction = 0; direction < 4; ++direction){
            int nx = t.x + dx[direction];
            int ny = t.y + dy[direction];
            if(safe(nx, ny) && dp[nx][ny][t.cnt] == -1 && !board[nx][ny]){
                Q.push({nx, ny, t.cnt});
                dp[nx][ny][t.cnt] = dp[t.x][t.y][t.cnt] + 1;
            }
        }

    }

    return -1;
}

int main(){
    scanf("%d%d%d", &jump, &w, &h);
    for(int x = 0; x < h; ++x){
        for(int y = 0; y < w; ++y){
            scanf("%d", &board[x][y]);
        }
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", bfs());
}

// 설명
// 최단거리라는 개념이 있기 때문에 너비 우선 탐색으로 풀어야 하는 문제다.
// 하나 더 필요한 것은 사방 으로 움직이는 것을 제하고, 체스에 나오는 
// 나이트만큼 이동할 수 있는 횟수가 주어진다.
// 그렇게 때문에 3차원 배열에 메모를 할 필요가 있다.