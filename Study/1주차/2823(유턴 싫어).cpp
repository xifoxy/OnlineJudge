#include <bits/stdc++.h>
using namespace std;
char board[11][11];
int dp[11][11];
int dx[]{-1, 0, 1, 0};
int dy[]{0, 1, 0, -1};
int n, m;
bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> board[i];
    }

    bool ans = true;
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < m; ++y){
            if(board[x][y] == '.'){
                for(int direction = 0; direction < 4; ++direction){
                    int nx = x + dx[direction];
                    int ny = y + dy[direction];

                    if(safe(nx,ny) && board[nx][ny] == '.'){
                        dp[x][y]++;
                    }
                }
                if(dp[x][y] <= 1) ans = false;
            }
        }
    }

    cout << !ans << '\n';
}

// 설명
// 문제 설명이 되게 장황하지만,
// 출력부분에도 힌트가 있고, 조금만 생각해보면 답을 어떻게 도출해야 할지 어렵지 않게 떠올릴 수 있다.

// 유턴 없이 그러니까, 왔던길로 돌아가는 방법 말고 도로를 무한히 순회 할 수 있으려면
// 현재 도로 타일 x,y와 연결된 도로 타일이 2개 이상이면 된다.

// 그러니 도로 타일마다 인접한(4방) 을 검사해 도로 타일이 1개 이하 일때 막다른 길이 되는것이다.