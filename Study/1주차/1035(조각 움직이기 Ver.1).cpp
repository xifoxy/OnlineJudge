#include <bits/stdc++.h>
using namespace std;
vector<int> vec, piece;
const int INF = 1e8;
char board[5][6];
bool visit[26];
int dx[]{1,-1,0,0};
int dy[]{0,0,1,-1};
int sz;
bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < 5 && y < 5;
}

// 색칠공부
void painting(bool val){
    for(auto &p : vec) visit[p] = val;
}

// DFS로 해당 좌표들이 죄다 붙어 있는지 확인한다.
// 붙어있으면 조각의 수만큼 값을 반환하겠지
int flood(int p){
    int cnt = 1;
    // 색칠 풀고
    visit[p] = false;
    for(int direction = 0; direction < 4; ++direction){
        // 1,2차원 좌표로 만들어서
        int nx = p / 5 + dx[direction];
        int ny = p % 5 + dy[direction];
        int idx = nx * 5 + ny;
        // 안전한지 검사하고 인접한 곳에 붙어 있는게 확인한다.
        if(safe(nx, ny) && visit[idx]){
            cnt += flood(idx);
        }
    }
    return cnt;
}

int getDist(){
    // 큰값으로 초기화를 한다음.
    int ret = INF;
    do{
        do{
            int sum = 0;

            // 구해진 좌표의 조합과 조각들의 좌표 조합으로 거리 최솟값을 구한다.
            for(int i = 0; i < sz; ++i){
                int cx = piece[i] / 5;
                int cy = piece[i] % 5;
                int nx = vec[i] / 5;
                int ny = vec[i] % 5;
                sum += abs(cx - nx) + abs(cy - ny);
            }
            ret = min(sum, ret);
        }while(next_permutation(piece.begin(), piece.end()));
    }while(next_permutation(vec.begin(), vec.end()));

    return ret;
}

int permutation(int cur){
    int ret = INF;

    // 만들어진 좌표의 수가 조각과 같다면
    if(vec.size() == sz){
        // 좌표를 칠해서
        painting(1);
        // 붙어있는지 확인한 다음
        if(flood(vec[0]) == sz)
            // 해당 좌표로 가는 이동 거리를 구한다.
            ret = getDist();

        // 그리고 칠했던걸 다시 풀어준다.
        painting(0);
        return ret;
    }

    // 좌표 조합
    for(int i = cur; i < 25; ++i){
        // 2차원 좌표를 1차원화 했으니까.
        vec.push_back(i);
        ret = min(ret, permutation(i + 1));
        vec.pop_back();
    }
    return ret;
}

int main(){
    for(int i = 0; i < 5; ++i){
        scanf("%s", &board[i]);


        // 2차원 좌표를 1차원으로 받기
        for(int idx = 0; idx < 5; ++idx){
            if(board[i][idx] == '*')
                piece.push_back(i * 5 + idx);
        }
    }
    sz = piece.size();
    vec.reserve(sz);
    int ans = permutation(0);

    printf("%d\n", ans == INF ? 0 : ans);
}

// 설명
// 창피할 정도로 더러운 소스다 -0-

// 로직의 흐름
// 1. 조각의 좌표를 입력받아서,
// 2. 5*5배열의 가능한 경우의 수를 전부 조합으로 만든다.. (ex. [0,1,2,3,4 ~ 20,21,22,23,24])
// 3. 만들어진 좌표들이 붙어 있는 조각의 형태이면 거리를 구하는 함수를 호출.
// 4. 조각들이 만들어진 좌표로 가는 순서는 상관없으나, 
//    어느 조각으로 가야 최솟값이 되는지 알 수 없으니 또 NextPermutation 해주며 구한다.