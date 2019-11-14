#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 1;
int board[M][M];
int dp[M*M];
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
int n, m, k;
bool safe(int x, int y){
    return min(x,y) >= 0 && x < n && y < m;
}

// Component의 크기 반환
int dfs(int x, int y){
    int ret = 1;
    board[x][y] = 1;
    for(int direction = 0; direction < 4; ++direction){
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        if(safe(nx, ny) && !board[nx][ny])
            ret += dfs(nx, ny);
    }

    return ret;
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    
    // 색칠놀이
    for(int idx = 0; idx < k; ++idx){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        for(int y = y1; y < y2; ++y){
            for(int x = x1; x < x2; ++x){
                board[y][x] = 1;
            }
        }
    }

    
    int ans = 0;
    // Component의 개수를 카운팅 하고 크기를 저장
    for(int x = 0; x < n; ++x)
        for(int y = 0; y < m; ++y)
            if(!board[x][y])
                dp[ans++] = dfs(x, y);

    sort(dp, dp + ans);
    printf("%d\n", ans);
    for(int idx = 0; idx < ans; ++idx){
        printf("%d ", dp[idx]);
    }
}

// 설명
// 도형 정말 싫다.
// 범위 작으니까 그냥 주어진 좌표안의 범위는 다 색칠해버리고
// Component의 크기와 개수를 저장한다.