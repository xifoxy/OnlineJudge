#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 1;

char board[M][M];
int dp[M * M];
int n, m;
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};

int jx = -1;

bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

// 불 확산시키기
void flood(queue<int> &Q){
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();

        for(int direction = 0; direction < 4; ++direction){
            int nx = cur / m + dx[direction];
            int ny = cur % m + dy[direction];
            int next = nx * m + ny;
            if(safe(nx, ny) && board[nx][ny] == '.' && !dp[next]){
                dp[next] = dp[cur] + 1;
                Q.push(next);
            }
        }
    }
}

bool isPossible(int x, int y){
    return x == 0 || y == 0 || x == n - 1 || y == m - 1;
}

// 지훈이 확산시키기
int sol(int pos){
    queue<int> Q;
    Q.push(pos);
    
    dp[pos] = 1;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();

        // 현재 좌표가 테두리에 도착했는지 검사
        if(isPossible(cur / m, cur % m)) return dp[cur];

        for(int direction = 0; direction < 4; ++direction){
            int nx = cur / m + dx[direction];
            int ny = cur % m + dy[direction];
            int next = nx * m + ny;
            // 불과 지훈이의 이동속도는 똑같기 때문에, 볼이 이동한 거리보다 작은 경우만 갈 수 있다.
            // 메모배열이 0인지 체크 하는 이유는, 불이 격리 되어 없는 경우를 위해서이다.
            if(safe(nx,ny) && board[nx][ny] == '.' && (dp[next] > dp[cur] + 1 || !dp[next])){
                dp[next] = dp[cur] + 1;
                Q.push(next);
            }
        }
    }
    
    return 0;
}

int main(){
    queue<int> fire;
    cin >> n >> m;
    for(int x = 0; x < n; ++x){
        cin >> board[x];
        
        // 공백 없는 문자열의 길이만큼 순회하는 방법
        for(int y = 0; board[x][y]; ++y){
            int cur = x * m + y;
            // 불을먼저 확산시키고 불보다 더 빨리 이동할수 있는 경우를 갱신하기 때문에.
            // 지훈이를 빈공간으로 만들어버린다.
            if(board[x][y] == 'J')
                jx = cur, board[x][y] = '.';
            
            // 예제에는 안나와 있지만, 불이 많을수도 있다.
            if(board[x][y] == 'F') {
                dp[cur] = 1;
                fire.push(cur);
            }
        }
    }

    flood(fire);
    int ans = sol(jx);
    if(!ans) puts("IMPOSSIBLE");
    else cout << ans;
}

// 설명(BFS)

// 친절하지 못한 문제이다. 문제와 테케만보고 추측해서 풀어야 한다.

// 1. 탈출하지 못하는 상황
//  ** 테두리와 연결된 길이 없다.
//  ** 불의 확산 속도를 못따라간다.
// 2. 불이 없다.

// 이정도를 보고 구현하면 될것 같다.