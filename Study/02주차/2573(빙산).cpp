#include <bits/stdc++.h>
using namespace std;
struct info{
    int x, y;
};

const int M = 301;

int board[M][M];
int temp[M][M];
bool visit[M][M];

int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};

int n, m;

queue<info> Q;

bool safe(int x, int y){
    return min(x, y) >= 0 && x < n && y < m;
}

// 빙산이 두개로 쪼개졌는지(Component 검사)
int dfs(int x, int y){
    int ret = 1;
    visit[x][y] = true;

    for(int direction = 0; direction < 4; ++direction){
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        if(board[nx][ny] && !visit[nx][ny]){
            ret += dfs(nx, ny);
        }
    }
    return ret;
}

int bfs(){
    int year = 0;
    while(!Q.empty()){
        // 현재의 빙산 정보를 temp배열에 저장한다.
        memcpy(temp, board, sizeof(board));
        memset(visit, false, sizeof(visit));
        int sz = Q.size();

        // 빙산이 두조각으로 나뉘어 졌는지 검사한다.
        // 컴포넌트가 두개로 쪼개져 있다면 답을 반환한다.
        int cnt = dfs(Q.front().x, Q.front().y);
        if(sz != cnt) return year;

        // 현재 큐에 들어있는 노드으 개수만큼 탐색제한을 둬서 년수를 카운팅한다.
        for(int idx = 0; idx < sz; ++idx){
            info t = Q.front();
            Q.pop();

            // 녹이기
            for(int direction = 0; direction < 4 && board[t.x][t.y]; ++direction){
                int nx = t.x + dx[direction];
                int ny = t.y + dy[direction];
                if(safe(nx, ny) && temp[nx][ny] == 0){
                    board[t.x][t.y]--;
                }
            }

            // 다 녹지 않았으면 큐에 박아버리기
            if(board[t.x][t.y])
                Q.push(t);
        }
        ++year;
    }
    return 0;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < m; ++y){
            scanf("%d", &board[x][y]);
            // 얼음이 존재하는 좌표는 전부다 큐에
            if(board[x][y])
                Q.push({x,y});
        }
    }
    printf("%d\n", bfs());
}

// 설명
// 얼음에 인접한 곳에 물이 존재한다면, 물이 존재하는 칸의 수만큼 녹는다.
// 하나 주의 해야할건, 변하기 전의 상태를 토대로 얼음이 녹기 때문에,
// X년 빙산을 갱신할때 X-1년의 빙산 정보를 가지고 있어야 한다.