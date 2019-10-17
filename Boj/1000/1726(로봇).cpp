#include <bits/stdc++.h>
using namespace std;
struct info{
    int x, y, dir;
};

const int M = 1e2+1;

int n, m;
int board[M][M];
int dp[M][M][4];

bool safe(int x, int y){
    return x > 0 && y > 0 && x <= n && y <= m && !board[x][y];
}

vector<int> get_direction(int dir){
    if(dir > 1) return {0,1};
    return {2,3};
}

int sx,sy,sd;
int ex,ey,ed;
// 0동 1서 2남 3북
int dx[]{0,0,1,-1};
int dy[]{1,-1,0,0};
int sol(){
    memset(dp, -1, sizeof(dp));
    scanf("%d%d%d", &sx,&sy,&sd);
    scanf("%d%d%d", &ex,&ey,&ed);
    
    ed--;
    sd--;

    int &ret = dp[ex][ey][ed];
    queue<info> Q;
    Q.push({sx,sy,sd});
    dp[sx][sy][sd] = 0;

    while(!Q.empty()){
        if(ret != -1) break;
        info t = Q.front();
        Q.pop();

        // Move Direction
        vector<int> direction = get_direction(t.dir);
        int &current = dp[t.x][t.y][t.dir];
        for(int i = 0; i < direction.size(); ++i){
            int &next = dp[t.x][t.y][direction[i]];
            if(next == -1 || current + 1 < next){
                next = current + 1;
                Q.push({t.x, t.y, direction[i]});
            }
        }
        
        // Go k = 1~3
        int cnt = 0;
        int nx = t.x + dx[t.dir];
        int ny = t.y + dy[t.dir];
        while(safe(nx,ny) && ++cnt <= 3){
            int &next = dp[nx][ny][t.dir];
            if(next == -1 || current + 1 < next){
                next = current + 1;
                Q.push({nx,ny,t.dir});
            }
            nx += dx[t.dir];
            ny += dy[t.dir];
        }
    }
    return ret;  
}

int main(){
    scanf("%d%d", &n,&m);
    for(int i = 1; i <= n ; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%d", &board[i][j]);
    printf("%d\n", sol());
}


// 설명(BFS, DP)
// 문제를 제대로 읽지 않아서 2번 틀렸다...
// 방향을 틀거나 GO: 1~3, 이 명령어들은 명령어 1회로 계산하고 DP배열을 채워나가면 된다.