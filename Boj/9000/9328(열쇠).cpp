#include <bits/stdc++.h>
using namespace std;

const int M = 101;

struct info{
    int x, y;
};

int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};

char board[M][M];
bool visit[M][M];

vector<bool> k(26);
vector<vector<info>> vec;
int n, m, tc;

bool safe(int x, int y){
    return min(x, y) >= 0 && x < n && y < m && board[x][y] != '*';
}

void eraseDoor(int idx, queue<info> &Q){
    k[idx] = true;

    // 문에 대한 정보를 전부 방문 가능상태로 만들어주고 큐에 박는다.
    for(auto &p : vec[idx]){
        board[p.x][p.y] = '.';
        Q.push({p.x, p.y});
    }
    vec[idx].clear();
}

bool isKey(char ch){
    return ch >= 'a' && ch <= 'z';
}

bool isDoor(char ch){
    return ch >= 'A' && ch <= 'Z';
}

int bfs(queue<info> &Q){
    int ret = 0;
    while(!Q.empty()){
        info t = Q.front();
        Q.pop();

        for(int direction = 0; direction < 4; ++direction){

            int nx = t.x + dx[direction];
            int ny = t.y + dy[direction];

            // * 벽이 아니면 일단 통과 시킨다.
            if(safe(nx,ny) && !visit[nx][ny]){

                visit[nx][ny] = true;
                char &ch = board[nx][ny];

                // 이 아래 부분은 main함수에서 했던 작업과 동일하다.
                if(isKey(ch)){
                    eraseDoor(ch - 'a', Q);
                    ch = '.';
                }

                if(isDoor(ch)){
                    if(k[ch - 'A'] == false) 
                        vec[ch - 'A'].push_back({nx,ny});
                    ch = k[ch - 'A'] ? '.' : ch;
                }

                if(ch == '$'){
                    ch = '.';
                    ret++;
                }

                if(ch == '.')
                    Q.push({nx,ny});
            }
        }
    }

    return ret;
}
void input(){
    // vec배열은 문에 대한 좌표를 담을 배열이다.
    vec.clear();
    vec.resize(26);
    memset(visit, false, sizeof(visit));
    // k배열은 열쇠 정보이다.
    fill(k.begin(), k.end(), false);

    scanf("%d%d", &n, &m);
    for(int x = 0; x < n; ++x)
        scanf("%s", &board[x]);

    char kTemp[26];
    scanf("%s", &kTemp);
    // 열쇠 입력받아서 소지상태로 만들기
    for(int idx = 0; kTemp[idx] != '0' && kTemp[idx]; ++idx){
        k[kTemp[idx] - 'a'] = true;
    }
}

int main(){
    scanf("%d", &tc);

    while(tc--){
        input();
        queue<info> Q;
        int cnt = 0;

        for(int x = 0; x < n; ++x){
            for(int y = 0; y < m; ++y){
                char &ch = board[x][y];
                // 테두리에 위치한 좌표이고,
                if(x == 0 || y == 0 || x == n - 1 || y == m - 1){
                    // 문서이면 정리해준다.
                    if(ch == '$')
                        cnt++, ch = '.';
                    
                    // 문을 만났을때
                    if(isDoor(ch)){
                        // 키를 가졌다면 열고,
                        ch = k[ch - 'A'] ? '.' : ch;

                        // 키가 없다면 정보를 저장한다.
                        if(ch != '.')
                            vec[ch - 'A'].push_back({x,y});
                    }
                    // 키를 만났다면, 저장되어 있는 해당 문에 대한 정보를 정리하고 큐에 담는다.
                    if(isKey(ch)){
                        eraseDoor(ch - 'a', Q);
                        ch = '.';
                    }

                    if(ch == '.')
                        Q.push({x,y});
                }
            }
        }
        printf("%d\n", bfs(Q) + cnt);
    } 
}

// 설명
// 예외를 잘 처리해줘야 하는 문제였다.

// 1. 상근이는 테두리에 열려있는 곳을 통해서 들어갈 수 있다.( '.', '$', 'key')
// 2. 열지 못하는 문을 만났을때는 문에 대한 정보를 담아둬야 할 필요가 있다. 열쇠를 주우면 재방문 해야 하기 때문이다.