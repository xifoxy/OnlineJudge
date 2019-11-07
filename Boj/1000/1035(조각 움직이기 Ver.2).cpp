#include <bits/stdc++.h>
using namespace std;

vector<int> piece, vec;
const int INF = 1e8;
char board[5][6];
bool visit[26];
bool visit2[26];
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
int sz;

bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < 5 && y < 5;
}
// 색칠 놀이
void painting(bool val){
    for(auto &p : vec) visit2[p] = val;
}

// 조합으로 구한 좌표가 붙어있는지 체크하는 함수
int flood(int p){
    int cnt = 1;
    visit2[p] = false;
    for(int direction = 0; direction < 4; ++direction){
        int nx = p / 5 + dx[direction];
        int ny = p % 5 + dy[direction];
        int idx = nx * 5 + ny;
        if(safe(nx, ny) && visit2[idx]){
            visit2[idx] = false;
            cnt += flood(idx);
        }
    }
    return cnt;
}

int ans = INF;
void permutation(int n, int dist){
    // 누적 된 거리가 현재 답보다 큰 경우 리턴을 하고.
    if(dist >= ans) return;

    // 구해진 좌표의 수가 같을 경우
    if(n == sz){
        // 붙어 있는지 확인을 위해 미리 색칠을한다.
        painting(true);
        // 그리고 좌표하나를 넘겨 붙어있는지 확인하며, 붙어있으면 값을 갱신한다.
        if(flood(vec[0]) == sz)
             ans = dist;

        // 붙어 있지 않은경우 색칠한곳이 남아있으니, 다음 검색을 위해 푼다.
        painting(false);
        return;
    }

    // 버전1과 다른 핵심 부분이다.
    // 버전1은 순차수열을 구하는 함수이고,
    // 버전2는 중복 없는 N개의 수를 뽑아내는 수열을 만드는 함수이다.
    // 그렇기에 이동해야할 거리를 바로구해서 넘겨주면 된다.
    for(int i = 0; i < 25; ++i){ 
        if(visit[i]) continue;
        int len = abs(i / 5 - piece[n] / 5) + abs(i % 5 - piece[n] % 5);
        visit[i] = true;
        vec.push_back(i);
        permutation(n + 1, dist + len);
        vec.pop_back();
        visit[i] = false;

    }
    return;
}

int main(){
    for(int i = 0; i < 5; ++i){
        scanf("%s", &board[i]);

        for(int idx = 0; idx < 5; ++idx){
            if(board[i][idx] == '*')
                piece.push_back(i * 5 + idx);
        }
    }
    sz = piece.size();
    vec.reserve(sz);
    permutation(0, 0);
    printf("%d\n", ans);
}

// 설명
// 버전1과 속도차이가 대략 10배정도 차이가 난다.

// 로직의 흐름
// 1. 조각의 좌표를 입력받아서,
// 2. 5*5배열의 가능한 경우의 수를 전부 조합으로 만들면서 *의 좌표와의 거리를 구해서 재귀로 넘긴다.
// 3. 구해진 값이 이전 값보다 작으면서 붙어 있으면 답을 갱신한다.