#include <bits/stdc++.h>
using namespace std;

const int M = 26;
int board[M*M];
int dp[M*M];
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
int n;

bool safe(int x, int y){
    return min(x, y) >= 0 && max(x, y) < n;
}

int dfs(int cur){
    board[cur] = 0;
    int ret = 1;
    for(int direction = 0; direction < 4; ++direction){
        int nx = dx[direction] + cur / n;
        int ny = dy[direction] + cur % n;
        int idx = nx * n + ny;
        if(safe(nx,ny) && board[idx])
            ret += dfs(idx);
    }
    return ret;
}

int main(){
    scanf("%d", &n);
    for(int x = 0; x < n; ++x)
        for(int y = 0; y < n; ++y)
            scanf("%1d", &board[x * n + y]);
    
    
    int idx = 1;
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < n; ++y){
            if(board[x * n + y]){
                dp[idx++] = dfs(x * n + y);
            }
        }
    }
    printf("%d\n", idx - 1);
    sort(dp, dp + idx);
    for(int i = 1; i < idx; ++i)
        printf("%d\n", dp[i]);
}

// 설명
// Component의 크기와 개수를 세면 된다.