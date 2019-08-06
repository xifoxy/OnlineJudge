#include <bits/stdc++.h>
using namespace std;
int cx[9], cy[9], cz[9];
int sudoku[10][10];
struct P{
    int x, y, z;
};
vector<P> v;
void dfs(int cur){
    // 0의 좌표를 입력해둔 모든 곳에 값이 들어가면
    // 출력하고 종료한다.
    if(cur == v.size()){
        for(int x = 0; x < 9; ++x){
            for(int y = 0; y < 9; ++y)
                printf("%d ", sudoku[x][y]);
            puts("");
        }
        exit(0);
    }
    P pos = v[cur];
    for(int num = 1; num <= 9; ++num){
        int bt = 1 << num;

        // 주석으로 설명한 조건에 따라, 해당 숫자가 한곳이라도 존재하면 통과
        if(cx[pos.x] & bt || cy[pos.y] & bt || cz[pos.z] & bt) continue;

        // 비트를 켜주고 재귀를 한다.
        sudoku[pos.x][pos.y] = num;
        cx[pos.x] |= bt;
        cy[pos.y] |= bt;
        cz[pos.z] |= bt;

        dfs(cur + 1);

        // 들어간 숫자가 맞지 않다면 리턴 되기때문에
        // 해당 숫자를 다시 꺼준다
        cx[pos.x] &= ~bt;
        cy[pos.y] &= ~bt;
        cz[pos.z] &= ~bt;
    }
}
int main(){
    int zero_cnt = 0;
    for(int x = 0; x < 9; ++x){
        for(int y = 0; y < 9; ++y){
            scanf("%d", sudoku[x] + y);
            // 3*3으로 칸을 나눈 인덱스
            int z_idx = x / 3 * 3 + y / 3;

            // OR연산을 이용해 입력된 숫자위치의 비트를 켜준다
            cx[x] |= (1 << sudoku[x][y]);
            cy[y] |= (1 << sudoku[x][y]);
            cz[z_idx] |= (1 << sudoku[x][y]);
            if(sudoku[x][y] == 0){
                // 중복되는 검사과정을 제한하기 위해 0의 위치를 저장한다.
                zero_cnt++;
                v.push_back({x, y, z_idx});
            }
        }
    }
    dfs(0);
}

// 설명(DFS)
// 스도쿠의 조건은 4가지가 있다.

// 1. 9*9의 스도쿠에는 1~9까지의 숫자만 존재한다.
// 2. X축의 숫자들은 유일해야 한다.
// 3. Y축의 숫자들은 유일해야 한다.
// 4. 9*9의 게임보드를 9개의(3*3)조각에도 숫자는 유일해야 한다.

// X축과 Y축은 나누기가 쉽다. 헌데, 3*3의 조각으로 나누는 곳에서 제법 심력소모를 했다.
// 그래도? 어떻게 나누긴 나눴다.

// 숫자의 존재 유무를 O(1)에 구하기 위한 방법으로 처음에 해당축에 리스트를 만들려고 했으나,
// 너무 비효율적인 방법인것같아 비트연산으로 해결했다.