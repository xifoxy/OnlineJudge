#include <bits/stdc++.h>
using namespace std;
struct P{
    int x, y;
};
const int M = 3e2+1;
int land[M][M], temp[M][M];
int dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
int n, m;
bool visit[M][M];

// 안전지역 확인
bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}

// 빙산크기 카운팅
int land_divide_check(P temp){
    queue<P> Q;
    Q.push(temp);
    int ret = 1;
    visit[temp.x][temp.y] = true;
    while(!Q.empty()){
        P currnet = Q.front();
        Q.pop();

        for(int direction = 0; direction < 4; ++direction){
            int nx = currnet.x + dx[direction];
            int ny = currnet.y + dy[direction];
            if(safe(nx,ny) && !visit[nx][ny] && land[nx][ny]){
                visit[nx][ny] = true;
                ret++;
                Q.push({nx,ny});
            }
        }
    }

    return ret;
}

int year;
int bfs(queue<P> &Q){
    while(!Q.empty()){
        // 한사이클 돌때마다 체크 해야 하기 때문에
        // visit배열을 초기화 해주고, 현재 시점의 land배열을 temp(prev)배열에 복사한다.
        memset(visit, false, sizeof(visit));
        memcpy(temp, land, sizeof(land));

        // 빙산의 좌표 하나로 flood fill을 진행했을시, 큐의 크기와 다르다면 빙산은 나뉜 것이다.
        int sz = land_divide_check(Q.front());
        if(sz != Q.size()) break;

        for(int i = 0; i < sz; ++i){
            P currnet = Q.front();
            Q.pop();

            for(int direction = 0; direction < 4; ++direction){
                int nx = currnet.x + dx[direction];
                int ny = currnet.y + dy[direction];

                // temp배열은 prev배열이다. 이전 정보를 가지고 갱신해야된다. 설명 참조
                if(safe(nx,ny) && temp[nx][ny] == 0 && land[currnet.x][currnet.y]){
                    land[currnet.x][currnet.y]--;
                }
            }
            // 인접공간을 탐색해도 빙산이 살아있으면 다시 큐에 삽입
            if(land[currnet.x][currnet.y])
                Q.push(currnet);
        }
        year++;
    }

    // 큐에 들어있는 빙산 좌표가 없다면? 빙산은 다 녹았기에 0을 반환하고
    // 큐에 정보가 들어 있다면 카운팅한 시간을 반환한다.
    return Q.size() ? year : 0;
}

int main(){
    scanf("%d%d",&n,&m);

    queue<P> Q;
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < m; ++y){
            scanf("%d", &land[x][y]);
            temp[x][y] = land[x][y];
            if(land[x][y]){
                Q.push({x,y});
            }
        }
    }
    printf("%d\n", bfs(Q));
}

// 설명(BFS, flood fill)
// 빙산의 상,하,좌,우로 인접한곳에 물이 존재한다면? 존재하는 방향 수 만큼 빙산이 녹는다.
// 문제에서 요구하는 답은 빙산이 녹는 중, 빙산이 두 조각 이상으로 나뉘는지 체크하는것 이다.
// 빙산이 다 녹으면 0을 출력해야 한다.

// 두가지의 작업이 필요했다.
// 1. 빙산의 조각이 두개 이상으로 나뉘었는지?
// 2. 빙산 녹이기

// 우선 솔루션의 탈출조건은 빙산이 다 녹는다 or 빙산이 두조각 이다. 이기 때문에
// 빙산의 정보가 필요하기에 값을 입력받을때 배열에(temp, land 배열이 2개인 이유?)에 입력받고, 
// 물이 아닌 빙산의 좌표는 queue에 추가한다.

// 처음 입력값에서 빙산이 두개로 들어올 수 있다는걸 가정해 탐색 시작지점에 빙산의 분할 여부를 체크한다.
// flood fill된 배열의 크기와, 큐에 닮긴 빙산의 좌표들의 사이즈가 같으면..
// 빙산의 인접한 부분들을 탐색해가면서 빙산을 정리해준다.
// 이 빙산을 녹이는 부분에서 배열을 두개 로 만든 이유가 있는데,

// 배열을 한개로 진행하게 되면,
// ex)
// 0 0 0 0     0 0 0 0
// 0 1 5 0 ==> 0 0 5 0
// 0 0 0 0     0 0 0 0
// 위와 같은 사태가 발생할 수 있다. 그래서 prev배열과 같은 개념으로 만든것이다.

// 빙산을 녹일때는
// 주어진 Input값의 크기가 최대 300*300로 제법 작기 때문에 큐에 넣고 빼기를 반복했다.