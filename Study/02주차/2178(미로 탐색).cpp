#include <bits/stdc++.h>
using namespace std;
const int M = 1e2 + 1;
char board[M][M];
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
int dp[M*M];
int n, m;
int safe(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}
int bfs(){
    queue<int> Q;
    Q.push(0);
    dp[0] = 0;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        
        for(int direction = 0; direction < 4; ++direction){
            int nx = cur / m + dx[direction];
            int ny = cur % m + dy[direction];
            int idx = nx * m + ny;
            if(safe(nx, ny) && dp[idx] == -1 && board[nx][ny] == '1'){
                dp[idx] = dp[cur] + 1;
                Q.push(idx);
            }
        }
    }
    return dp[n * m - 1] + 1;
}
int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;

    for(int x = 0; x < n; ++x){
        cin >> board[x];
    }

    cout << bfs() << '\n';
}

// 설명
// 최단거리를 구해야 하기 때문에 BFS를 이용해야한다.