#include <bits/stdc++.h>
using namespace std;
int arr[5][5];
int dx[]{0,1};
int dy[]{1,0};
int ddx[]{1,-1};
int ddy[]{1,1};
bool sol(int nnn){
    int cnt = 0;
    for(int i = 0; i < 5; ++i){
        int x = i;
        int y = 0;
        for(int direc = 0; direc < 2; ++direc){
            if(direc) x = 0, y = i;
            for(int k = 0; k < 4 && !arr[x][y]; ++k){
                x += dx[direc];
                y += dy[direc];
                if(arr[x][y]) break;
                if(k == 3) cnt++;
            }
        }
    }
    for(int direc = 0; direc < 2; ++direc){
        int x = 0;
        int y = 0;
        if(direc) x = 4;
        for(int i = 0; i < 4 && !arr[x][y]; ++i){
            x += ddx[direc];
            y += ddy[direc];
            if(arr[x][y]) break;
            if(i == 3) cnt++;
        }
    }
    return cnt > 2;
}
int main(){
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            scanf("%d", &arr[i][j]);
        }
    }
    int num, ans;
    bool check = false;
    for(int tc = 0; tc < 25; ++tc){
        scanf("%d", &num);

        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 5 && !check; ++j){
                if(arr[i][j] == num){
                    arr[i][j] = 0;
                    check = sol(tc);
                }
                if(check) ans = tc + 1;
            }
        }
    }
    printf("%d\n", ans);
}

// 설명(Simulation)
// 노가다 정말 싫다.