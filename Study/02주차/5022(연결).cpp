#include <bits/stdc++.h>
using namespace std;

const int M = 110;
const int INF = 1e8;

struct info{
    int x, y, distance;
};

info A[2], B[2];

int w, h;
int board[M][M];
int dx[]{0,-1,0,1,0};
int dy[]{0,0,-1,0,1};

bool safe(int x, int y){
    return min(x, y) >= 0 && x < w && y < h;
}

// 지나온 경로를 색칠하는 방법
void pathPainting(const info &a, const info &b){
    int nx = a.x;
    int ny = a.y;
    int direction = 0;
    
    // 되돌아 가며 색칠 하는 방법은 비교적 간단하다.
    // 더해주면서 퍼트렸기 때문에, 반대로 빼주면 지나온 좌표로 갈 수 있다.
    while(nx != b.x || ny != b.y){
        direction = board[ny][nx];
        board[ny][nx] = 0;
        nx -= dx[direction];
        ny -= dy[direction];
    }

    // 색칠 해준 경로를 제외하고 방문 가능상태로 만들어준다.
    for(int x = 0; x < w; ++x){
        for(int y = 0; y < h; ++y){
            if(board[y][x] != 0)
                board[y][x] = -1;
        }
    }
}

// 좌표 색칠하기
void posPainting(info a, info b, int val){
    board[a.y][a.x] = board[b.y][b.x] = val;
}

// 0은 표시된 경로 혹은 좌표이다.
// -1은 방문 가능한 좌표이다.

int BFS(const info *a, const info *b){
    queue<info> Q;
    Q.push(a[0]);

    // A좌표를 연결하려면,
    // B좌표와 A[0] 좌표를 방문하지 못하도록 사용 상태로 만들어야 한다.
    posPainting(b[0], b[1], 0);
    board[a[0].y][a[0].x] = 0;    
    while(!Q.empty()){
        info t = Q.front();
        Q.pop();

        // A[1] 좌표에 도달했으면,
        // 지나오면 경로를 색칠해준다.
        if(t.x == a[1].x && t.y == a[1].y){
            pathPainting(a[1], a[0]);
            
            // B의 경로를 연결 해줘야 하기 때문에 방문 가능 상태로 초기화 해준다.
            posPainting(b[0], b[1], -1);

            return t.distance;
        }

        for(int direction = 1; direction <= 4; ++direction){
            int nx = t.x + dx[direction];
            int ny = t.y + dy[direction];

            if(safe(nx, nx) && board[ny][nx] == -1){
                board[ny][nx] = direction;
                Q.push({nx, ny, t.distance + 1});
            }
        }

    }
    return INF;
}

void input(info *arr){
    for(int idx = 0; idx < 2; ++idx){
        scanf("%d%d", &arr[idx].x, &arr[idx].y);
        arr[idx].distance = 0;
    }
}

int main(){
    while(1){
        scanf("%d%d", &w, &h);
        input(A);
        input(B);

        // 6*6이 주어졌으면, 필요한건 7*7배열이다.
        w -= -1;
        h -= -1;

        memset(board, -1, sizeof(board));
        int a = BFS(B, A) + BFS(A, B);

        memset(board, -1, sizeof(board));
        int b = BFS(A, B) + BFS(B, A);

        int ans = min(a, b);
        if(ans >= INF) puts("IMPOSSIBLE");
        else printf("%d\n", ans);
    }
}

// 설명
// 이 문제의 핵심은 지나온 경로를 다시 되돌아 가는 방법에 있다.
// 그리고 (A->A1 B->B1), (B->B1 A->A1) 두 가지 연결하는 최단거리가 
// 다를 수 있으니 둘다 해본다.