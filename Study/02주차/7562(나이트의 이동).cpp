#include <bits/stdc++.h>
using namespace std;

struct info{
    int x, y;
};

const int M = 3e2+1;

int dx[]{-1,-2,-2,-1,1,2,2,1};
int dy[]{-2,-1,1,2,-2,-1,1,2};

int board[M][M];
int n, tc;
bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < n;
}

int x, y;

int bfs(queue<info> &Q){

    while(!Q.empty()){
        info t = Q.front();
        Q.pop();

        if(t.x == x && t.y == y) break;

        // 나이트는 8곳을 이동할 수 있다.
        for(int direction = 0; direction < 8; ++direction){
            int nx = t.x + dx[direction];
            int ny = t.y + dy[direction];
            if(safe(nx, ny) && board[nx][ny] == -1){
                board[nx][ny] = board[t.x][t.y] + 1;
                Q.push({nx,ny});
            }
        }
    }

    return board[x][y];
}

int main(){
    scanf("%d", &tc);
    while(tc--){
        memset(board, -1, sizeof(board));
        queue<info> Q;
        scanf("%d%d%d", &n, &x, &y);
        board[x][y] = 0;
        Q.push({x,y});
        scanf("%d%d", &x, &y);
        printf("%d\n", bfs(Q));
    }
}

// 설명
// 최단거리가 답이기 때문에 BFS를 이용한다.
// 현재 나이트의 위치에서 방문가능 한 모든곳을 Flood Fill 해주면 된다.