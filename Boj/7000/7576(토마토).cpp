#include <bits/stdc++.h>
using namespace std;

const int M = 1e3 + 1;

int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};

int board[M][M];

int n, m, seed;

bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}
queue<int> Q;

int bfs(){
    int day = 0;
    while(!Q.empty() && seed){
        ++day;

        // 날짜를 계산해주기 위해
        // 큐에 담긴 토마토만큼 탐색을 한다.
        int sz = Q.size();
        for(int idx = 0; idx < sz; ++idx){
            int cur = Q.front();
            Q.pop();

            for(int direction = 0; direction < 4; ++direction){
                int nx = cur / m + dx[direction];
                int ny = cur % m + dy[direction];
                if(safe(nx,ny) && board[nx][ny] == 0){
                    board[nx][ny] = 1;
                    Q.push(nx * m + ny);
                    --seed;
                }
            }
        }
    }

    // 색칠놀이를 마쳤는대도 씨앗이 존재하면 -1을 반환한다.
    return seed ? -1 : day;
}

int main(){
    scanf("%d%d", &m, &n);

    for(int x = 0; x < n; ++x){
        for(int y = 0; y < m; ++y){
            scanf("%d", &board[x][y]);
            // 토마토는 큐에
            if(board[x][y] == 1)
                Q.push(x * m + y);
            
            // 심어진 시앗 카운트
            if(!board[x][y])
                seed++;
        }
    }
    printf("%d\n", bfs());
}

// 설명
// 심어놓은 종자를 다 틔울수 있는지에 대해서 Flood Fill 한다.
// 토마토가 존재하면 인접한 씨앗은 토마토가 된다.