#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[51][51];
bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

int sol(int x, int y){
    int ret = 1;
    for(int i = 0; ; ++i){
        if(safe(x + i, y + i)){
            if(board[x][y] == board[x][y + i] && board[x][y] == board[x + i][y] && board[x][y] == board[x + i][y + i])
                ret = max(ret, i + 1);
        } else break;
    }
    return ret * ret;
}

int main(){
    scanf("%d%d", &n,&m);
    for(int i = 0; i < n; ++i){
        scanf("%s", board[i]);
    }

    int ans = 1;
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < m - 1; ++j){
            ans = max(ans, sol(i, j));
        }
    }
    printf("%d\n", ans);
}

// 각 좌표마다 완탐하면 된다.