#include <bits/stdc++.h>
using namespace std;

string str;
char board[222][22];
int main(){
    int n, idx = 0, x = 0, y = 0;
    cin >> n >> str;
    fill(&board[0][0], &board[221][n + 1], '.');
    while(1){
        while(y < n && idx < str.size()){
            board[x][y++] = str[idx++];
        }
        ++x;
        if(idx == str.size()) break;
        while(y > 0 && idx < str.size()){
            board[x][--y] = str[idx++];
        }
        ++x;
        if(idx == str.size()) break;
    }

    idx = 0;
    for(int i = 0; i < n; ++i){
        for(int y = 0; y < x && board[y][i] != '.'; ++y, ++idx){
            printf("%c", board[y][i]);
        }
    }
}

// 말하지 않아도 알아요