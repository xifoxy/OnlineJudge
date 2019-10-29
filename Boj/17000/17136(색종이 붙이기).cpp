#include <bits/stdc++.h>
using namespace std;
int paper[6]{0,5,5,5,5,5};
int board[11][11];
bool visit[11][11];
int cnt;
const int INF = 999;

// 덮기 혹은 겉기
void paint(int cur_x, int cur_y, int range){
     for(int x = cur_x; x < cur_x + range; ++x){
        for(int y = cur_y; y < cur_y + range; ++y){
            visit[x][y] = !visit[x][y];
        }
    }
}

// 덮으려고 하는 구간이 1로만 되어 있는지 검사
bool check(int cur_x, int cur_y, int range){
    if(cur_x + range > 10 || cur_x + range > 10)
        return false;

    for(int x = cur_x; x < cur_x + range; ++x){
        for(int y = cur_y; y < cur_y + range; ++y){
            if(visit[x][y] || !board[x][y])
                return false;
        }
    }
    return true;
}

int sol(int using_paper){
    int ret = INF;

    // 다 덮었다면 사용한 종이갯수 리턴
    if(cnt == 0)
        return using_paper;
    
    // 덮지 않은 부분을 찾는다.
    bool isfind = true;
    int nx = -1, ny = -1;
    for(int x = 0; x < 10 && nx == -1; ++x){
        for(int y = 0; y < 10; ++y){
            if(board[x][y] && !visit[x][y]){
                nx = x;
                ny = y;
                break;
            }
        }
    }

    // 사실 이건 없어도 된다.
    if(nx == -1) return ret;


    // 덮지 않은 부분의 x,y의 좌표를 기준으로
    // 종이가 존재하면서 x+1~5 && y+1~5가 가능한 부분이 있다면
    for(int range = 1; range <= 5; ++range){
        if(paper[range] && check(nx, ny, range)){
            // 종이의 갯수를 줄이고
            paper[range]--;
            // 덮은다음에
            cnt -= (range * range);
            paint(nx, ny, range);

            // 재귀를 탄다.
            ret = min(ret, sol(using_paper + 1));

            // 탈출했으면 다시 원상복구 시킨다.
            paper[range]++;
            cnt += (range * range);
            paint(nx, ny, range);
        }
    }

    return ret;
}
int main(){
    for(int x = 0; x < 10; ++x){
        for(int y = 0; y < 10; ++y){
            scanf("%d", &board[x][y]);
            // 답 체크를 위해서 덮어야할 칸의 개수를 구한다.
            if(board[x][y]) cnt++;
        }
    }

    int ans = sol(0);
    printf("%d\n", ans == INF ? -1 : ans); 
}

// 설명(Brute Force, Next Permutation)
// 노가다 문제이다.
// 종이를 덮을 조합함수를 구현해야 하고 나머지 본인이 생각한 시뮬레이션대로 구현하면된다.