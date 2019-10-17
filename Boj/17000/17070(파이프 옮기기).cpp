#include <bits/stdc++.h>
using namespace std;
struct info{
    int x, y, dir;
}; 
const int M = 40;
int dx[]{0,1,1};
int dy[]{1,1,0};
int board[M][M];
long long dp[M][M][3];
int n;

bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < n && !board[x][y];
}
vector<int> get_direction(int dir){
    if(!dir) return {0,1};
    if(dir == 1) return {0,1,2};
    return {1,2};
}
long long sol(int x, int y, int dir){
    if(x == n - 1 && y == n - 1) return 1;
    long long &ret = dp[x][y][dir];

    if(ret != -1) return ret;
    vector<int> direction = get_direction(dir);

    ret = 0;
    for(auto &idx : direction){
        int nx = x + dx[idx];
        int ny = y + dy[idx];
        if(safe(nx,ny)){
            if(idx == 1){
                if(safe(x + 1, y) && safe(x,  y + 1))
                    ret += sol(nx, ny, idx);
            } else ret += sol(nx, ny, idx);
        }
    }
    return ret;
}

int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < n; ++y){
            scanf("%d", &board[x][y]);
        }
    }
    printf("%lld", sol(0,1,0));
}

// 파이프 옮기기2 참조