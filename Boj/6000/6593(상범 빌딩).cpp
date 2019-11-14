#include <bits/stdc++.h>
using namespace std;
struct info{
    int f, x, y;
};
const int M = 31;

char board[M][M][M];
int dp[M][M][M];

int df[]{0,0,0,0,1,-1};
int dx[]{1,-1,0,0,0,0};
int dy[]{0,0,1,-1,0,0};

int f, h, w;

info SB, ES;

bool safe(int fl, int x, int y){
    return min(fl, min(x, y)) >= 0 && x < h && y < w &&
            dp[fl][x][y] == -1 && board[fl][x][y] == '.'; 
}
int BFS(){
    queue<info> Q;
    Q.push(SB);
    dp[SB.f][SB.x][SB.y] = 0;

    while(!Q.empty()){
        info t = Q.front();
        Q.pop();

        // 최단거리를 검색하는 것이기에, 따로 더 검사할게 없다.
        // 방문가능한 부분인지만 검사하면 된다.
        for(int direction = 0; direction < 6; ++direction){
            int nf = t.f + df[direction];
            int nx = t.x + dx[direction];
            int ny = t.y + dy[direction];
            if(safe(nf,nx,ny)){
                dp[nf][nx][ny] = dp[t.f][t.x][t.y] + 1;
                Q.push({nf, nx, ny});
            }
        }
    }

    return dp[ES.f][ES.x][ES.y];
}

int main(){
    while(scanf("%d%d%d", &f, &h, &w), f){
        memset(dp, -1, sizeof(dp));
        
        for(int floor = 0; floor < f; ++floor){
            for(int x = 0; x < h; ++x){
                scanf("%s", &board[floor][x]);

                for(int y = 0; board[floor][x][y]; ++y){
                    if(board[floor][x][y] == 'S')
                        SB = {floor, x, y};
                    
                    // 좌표 기준 탐색을 위해 탈출구도 . 으로 표기
                    if(board[floor][x][y] == 'E')
                        ES = {floor, x, y}, board[floor][x][y] = '.';
                }
            }
        }

        int ans = BFS();
        if(ans == -1) puts("Trapped!");
        else printf("Escaped in %d minute(s).\n", ans);
    }
}

// 설명
// 3차원 토마토랑 다를게 없다. 그냥 층만 추가된거다.