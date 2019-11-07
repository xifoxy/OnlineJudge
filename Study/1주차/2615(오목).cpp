#include <bits/stdc++.h>
using namespace std;

const int M = 19;
int dx[]{1,0,1,-1};
int dy[]{0,1,1,1};

int board[M + 1][M + 1];
bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < M && y < M;
}
int main(){
    for(int i = 0; i < M; ++i)
        for(int j = 0; j < M; ++j)
            scanf("%d", &board[i][j]);
    
    
    bool ans = false;
    for(int x = 0; x < M; ++x){
        for(int y = 0; y < M; ++y){
            if(!board[x][y]) continue;

            for(int direction = 0; direction < 4 && !ans; ++direction){
                int nx = x;
                int ny = y;
                int cnt = 0;

                while(safe(nx, ny) && board[nx][ny] == board[x][y]){
                    cnt++;
                    nx += dx[direction];
                    ny += dy[direction];
                }

                nx = x - dx[direction];
                ny = y - dy[direction];
                if(cnt == 5 && (!safe(nx, ny) || board[nx][ny] != board[x][y])){
                    ans = true;
                    printf("%d\n%d %d", board[x][y], x + 1, y + 1);
                }
            }
        }
    }
    if(ans == false)
        puts("0");
}

// 설명
// 탐색 방향이 중요한 문제이다.
// 우선 출력란을 읽어보면..
// 1. 무승부는 0으로 출력한다.
// **2. 이긴 바둑알의 번호를 출력하고, 오목이 완성된 가장 왼쪽 바둑알의 좌표를 출력한다.

// 그러니까 2번 말대로 구현하려면.. ↓ → ↘ ↗ 이렇게 4방향으로 검색하면서 답을 찾으면 된다.