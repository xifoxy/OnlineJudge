#include <bits/stdc++.h>
using namespace std;

const int M = 51;
bool board[M][M];
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
int tc;
int n, m, k;

bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < m && y < n;
}

void dfs(int x, int y){
    // 색칠풀기
    board[x][y] = false;

    for(int direction = 0; direction < 4; ++direction){
        int nx = x + dx[direction];
        int ny = y + dy[direction];

        // 사방탐색을 통해 연결된 노드를 찾으면 방문한다.
        if(safe(nx, ny) && board[nx][ny])
            dfs(nx, ny);
    }
}
int main(){
    scanf("%d", &tc);

    while(tc--){
        memset(board, false, sizeof(board));
        scanf("%d%d%d", &m, &n, &k);

        // M*N 배열에 K개의 노드가 주어진다. 노드에 색칠하기.
        for(int idx = 0; idx < k; ++idx){
            int x, y;
            scanf("%d%d", &x, &y);
            board[x][y] = true;
        }
        int ans = 0;

        // 색칠되어 있는 노드를 만나면 Component의 개수를 증가 시켜주고,
        // 연결된 요소들을 전부 확인한다.
        for(int x = 0; x < m; ++x){
            for(int y = 0; y < n; ++y){
                if(board[x][y])
                    dfs(x,y), ++ans;
            }
        }
        printf("%d\n", ans);
    }
}

// 설명
// Component의 개수가 답인, 즉 연결요소의 개수를 세는 문제이다.
// 특정 노드에 상,하,좌,우 에 연결되어 있는 노드가 있으면,
// 하나의 Component에 속해 있게 된다.