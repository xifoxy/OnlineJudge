#include <bits/stdc++.h>
using namespace std;
struct info{
    int x, y;
};
const int M = 51;

char board[M][M];
int hei[M][M];
bool visit[M][M];
int n, deliver;
int Min, Max;

info p;
vector<int> vec;

// 입력받기
void input(){
    scanf("%d", &n);
    vec.reserve(n*n);
    for(int x = 0; x < n; ++x){
        scanf("%s", &board[x]);

        for(int y = 0; y < n; ++y){
            if(board[x][y] == 'P')
                p = {x,y};
            if(board[x][y] == 'K')
                deliver++;
        }
    }

    for(int x = 0; x < n; ++x){
        for(int y = 0; y < n; ++y){
            scanf("%d", &hei[x][y]);
            vec.push_back(hei[x][y]);
        }
    }

    // 후보수를 정렬하고, 중복되는 후보수들 제거
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
}

int dx[]{1,-1,0,0,-1,-1,1,1};
int dy[]{0,0,1,-1,-1,1,-1,1};

bool safe(int x, int y){
    return min(x,y) < 0 || max(x,y) == n || visit[x][y];
}
bool range(int num){
    return num < Min || num > Max;
}

int dfs(int x, int y){
    // 검사를 DFS시작단에서 하는 이유는,
    // 시작점인 우체국 또한 범위에 포함되어야 하기 때문이다.
    if(range(hei[x][y]) || safe(x,y)) return 0;
    int ret = 0;
    visit[x][y] = true;
    if(board[x][y] == 'K') ret++;
    for(int direction = 0; direction < 8; ++direction){
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        ret += dfs(nx,ny);
    }
    return ret;
}

int main(){
    input();

    int ans = 1e8;
    int l = 0, r = 0;
    // Sliding WindoooooooooW
    while(l <= r && r < vec.size()){
        Min = vec[l], Max = vec[r];

        memset(visit, false, sizeof(visit));
        int K = dfs(p.x, p.y);
        
        // DFS로 반환된 숫자가 배달해야 하는 숫자와 같다면
        // L을 늘려 갭을 줄인다.
        if(K == deliver){
            ans = min(vec[r] - vec[l], ans);
            ++l;
        } else ++r;
    }

    printf("%d\n", ans);
}

// 설명
// 처음에는 각 집마다 우체국으로 가는 고도의 최저와 최대치를 구하는 방법으로 접근했었다.
// 그런데 너무 드러운 시간복잡도와 난잡한 솔루션이 될것 같아 질게를 보았는데,
// 각 노드가 최대 최소의 후보가 될 수 있다는 것에서 힌트를 얻었다.