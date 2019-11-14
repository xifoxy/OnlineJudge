#include <bits/stdc++.h>
using namespace std;

struct info{
    int x, y, direc, cnt;
};

const int M = 1e2+1;
char board[M][M];
int dp[M][M];

int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};

int n, m;

info laser[2];

bool safe(int x, int y){
    return min(x,y) >= 0 && x < n && y < m && board[x][y] == '.';
}

int bfs(){
    queue<info> Q;

    dp[laser[0].x][laser[0].y] = 0;

    // C가 있는 Node에서 4방향으로 보내는 레이저
    for(int direc = 0; direc < 4; ++direc){
        laser[0].direc = direc;
        Q.push(laser[0]);
    }

    while(!Q.empty()){
        info t = Q.front();
        Q.pop();

        for(int direction = 0; direction < 4; ++direction){
            int nx = t.x + dx[direction];
            int ny = t.y + dy[direction];
            int nCnt = direction == t.direc ? t.cnt : t.cnt + 1;
            // 레이저 마다 방향성이 존재하기 때문에,
            // 현재 값 보다 큰 경우를 생각해야한다.
            if(safe(nx,ny) && (dp[nx][ny] == -1 || dp[nx][ny] >= nCnt)){
                dp[nx][ny] = nCnt;
                Q.push({nx,ny,direction,nCnt});
            }
        }
    }
    return dp[laser[1].x][laser[1].y];
}

int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d%d", &m, &n);

    for(int x = 0, idx = 0; x < n; ++x){
        scanf("%s", &board[x]);
        for(int y = 0; board[x][y]; ++y){
            // 좌표기준 탐색을 위해서 연결해야 하는 부분 또한 . 으로 바꾼다.
            if(board[x][y] == 'C')
                laser[idx++] = {x,y},
                board[x][y] = '.';
        }
    }

    printf("%d\n", bfs());
}

// 설명
// 아이디어가 떠오르면 생각보다 간단하다.
// 거울이 설치된다는건 방향이 꺾인다는 말이니,
// 방향이 꺾여야만 방문 가능한 곳은 거울이 설치되는 곳이다.