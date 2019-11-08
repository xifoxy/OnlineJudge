#include <bits/stdc++.h>
using namespace std;

const int M = 64;
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
int board[M];
int n, m, sz, air = -3; // 벽을 3개 꼭 세워야 하니까.

queue<int> Q, virus;
bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}
int BFS(){
    int temp[M];

    // 벽을 세운 배열정보 복사
    memcpy(temp, board, sizeof(board));
    int ret = 0;
    Q = virus;

    // 색칠놀이
    while(!Q.empty()){
        int t = Q.front();
        Q.pop();
        for(int direction = 0; direction < 4; ++direction){
            int nx = t / m + dx[direction];
            int ny = t % m + dy[direction];
            int next = nx * m + ny;
            if(safe(nx, ny) && temp[next] == 0){
                ret++;
                temp[next] = 2;
                Q.push(next);
            }
        }
    }
    return air - ret;
}
int sol(int x, int y, int wall){
    if(wall == 3){
        return BFS();
    }
    int ret = 0;

    // 2차원 배열 1차원화 시키고 조합 구하기
    for(int idx = x * m + y; idx < sz; ++idx){
        if(board[idx] == 0){
            board[idx] = 1;
            ret = max(ret, sol(idx / m, idx % m, wall + 1));
            board[idx] = 0;
        }
    }

    return ret;
}
int main(){
    cin >> n >> m;
    sz = n * m;
    for(int idx = 0; idx < sz; ++idx){
        cin >> board[idx];
        if(board[idx] == 0) air++;
        if(board[idx] == 2)
            virus.push(idx);
    }

    cout << sol(0, 0, 0);
}

// 설명(Next_Permutation, BFS)
// 배열의 크기가 작으니 완전 탐색부터 접근해보자. 배열의 최대 크기는 8*8 = 64 이니..
// 조합계산기로 64! / ((64 - 3)! * 3!) 해보면 41664이 나온다.
// 그러니 로직의 순서는

// 1. 벽을 세울곳을 조합으로 구하고,
// 2. 바이러스가 닮긴 정보로 BFS하여 색칠놀이를 한다.