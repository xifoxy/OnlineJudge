#include <bits/stdc++.h>
using namespace std;
const int M = 17;
struct info{ int x, y; };
int dx[]{0,-1,0};
int dy[]{-1,0,1};
bool visit[M][M];
int n, m, range, cnt;
vector<vector<int>> board;
bool safe(int x, int y){ return x >= 0 && y >= 0 && x < n && y < m; }

int sol(vector<int> &pos, vector<vector<int>> &t_board){
    memset(visit, false, sizeof(visit));
    vector<vector<int>> temp = t_board;
    int ret = 0;
    // 적들이 내려오는 시뮬레이션 이기 때문에
    // 궁수를 제일 아래부터 위로 한칸씩 올린다는 가정으로 만들었다.
    for(int x = n - 1; x >= 0; --x){
        // 없앨 적을 담을 큐
        queue<info> QQ;

        // 궁수 위치(Y축))
        for(int i = 0; i < pos.size();++i){
            int y = pos[i];

            // 적을 만나면 큐에 담는다.
            if(temp[x][y]) {
                QQ.push({x,y});
                continue;
            }
            queue<info> Q;
            Q.push({x,y});
            
            // 적을 못만났을 경우 공격 가능한 거리만큼 탐색한다.
            // cmp변수로 탈출구를 만든다.
            bool cmp = true;
            for(int distance = 0; distance < range && cmp; ++distance){
                int sz = Q.size();
                for(int idx = 0; idx < sz && cmp; ++idx){
                    info t = Q.front();
                    Q.pop();

                    for(int direc = 0; direc < 3 && cmp; ++direc){
                        int nx = t.x + dx[direc];
                        int ny = t.y + dy[direc];
                        if(safe(nx,ny)){
                            Q.push({nx,ny});
                            // 공격할 수 있는 적이면 큐에 담고 탈출한다.
                            if(temp[nx][ny]){
                                cmp = false;
                                QQ.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }

        // 공격한 적을 없애는 작업을 하면서
        // 값을 카운팅한다.
        while(!QQ.empty()){
            info t = QQ.front();
            QQ.pop();

            // 똑같은 적을 쳤는지에 대한 조건확인
            if(temp[t.x][t.y])
                ret++;
            temp[t.x][t.y] = 0;
        }
    }
    return ret;
}

// 조합
int permutation(int cur, vector<int> &pos){
    if(pos.size() == 3)
        return sol(pos, board);

    int ret = 0;

    for(int y = cur; y < m; ++y){
        pos.push_back(y);
        ret = max(ret, permutation(y + 1, pos));
        pos.pop_back();
    }

    return ret;
}
int main(){
    scanf("%d%d%d", &n,&m,&range);
    // 일부로 공격 거리를 하나 줄였다.
    // 5*5 배열이면 6*5로 만들지 않게 하기 위해서다.
    range--;
    board.resize(n, vector<int>(m));
    for(int x = 0; x < n; ++x)
        for(int y = 0; y < m; ++y)
            scanf("%d", &board[x][y]);

    vector<int> pos;
    printf("%d\n", permutation(0, pos));
}

// 설명(NextPermutation, Simulation)
// 생각 없이 막짜다 보니 소스가 너어어어어어어어어무 더러워졌다.
// 궁수를 배치 할 수 있는 조합 함수가 필요하고,
// 시뮬레이션 할 함수가 필요하다.
// 문제는 어렵지 않은데 조건을 잘 읽어봐야 한다 이게 조금 까다롭게 느껴졌다.
// 1. 거리가 같으면 제일 왼쪽에 있는걸 친다.
// 2. 모든 궁수는 같은것을 공격할 수 있다.
// 1번 조건을 형성하기위해서 탐색할때 쓰는 direction배열을 ←↑→순서로 만들어줄 필요가 있다.
// 나머지는 소스속에 주석을 보면 될것 같다.