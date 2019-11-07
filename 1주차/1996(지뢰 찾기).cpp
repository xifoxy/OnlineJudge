#include <bits/stdc++.h>
using namespace std;

const int M = 1e3 + 1;
char board[M][M];
int cnt[M][M];
int dx[]{1,-1,0,0,-1,-1,1,1};
int dy[]{0,0,1,-1,-1,1,-1,1};
int n;

bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < n;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%s", &board[i]);
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(board[i][j] != '.'){
                cnt[i][j] = -1;
                continue;
            }

            for(int direction = 0; direction < 8; ++direction){
                int nx = i + dx[direction];
                int ny = j + dy[direction];
                if(safe(nx,ny) && board[nx][ny] != '.'){
                    cnt[i][j] += board[nx][ny] - '0';
                    if(cnt[i][j] > 9){
                        cnt[i][j] = -2;
                        break;
                    }
                }
            }
            
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(cnt[i][j] == -1  || cnt[i][j] == -2)
                printf("%c", cnt[i][j] == -1 ? '*' : 'M');
            else printf("%d", cnt[i][j]);
        }
        puts("");
    }
}

// 설명
// 주어진 좌표가 지뢰가 아니라면, 8방 탐색을 통해 주변 지뢰를 더해주면된다.