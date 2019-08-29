#include <bits/stdc++.h>
using namespace std;
struct P{
    int x, y;
};
char land[51][51];
int depth[51][51];
int dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
int n, m;
bool safe(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m && land[x][y] == 'L';
}
int bfs(int x, int y){
    memset(depth, 0, sizeof(depth));
    int ret = depth[x][y] = 1;
    queue<P> Q;
    Q.push({x, y});
    while(!Q.empty()){
        P pos = Q.front();
        Q.pop();
        for(int direction = 0; direction < 4; ++direction){
            int nx = pos.x + dx[direction];
            int ny = pos.y + dy[direction];
            if(safe(nx,ny) && depth[nx][ny] == 0){
                Q.push({nx,ny});
                depth[nx][ny] = depth[pos.x][pos.y] + 1;
                ret = max(depth[nx][ny], ret);
            }
        }
    }
    return ret;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i)
        scanf("%s", land[i]);

    int ans = 0;
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < m; ++y){
            if(land[x][y] == 'L'){
                ans = max(ans, bfs(x, y));
            }
        }
    }
    printf("%d\n", ans - 1);
}

// 설명(BFS)
// 문제의 설명에 "보물은 서로 간에 최단 거리로 이동하는데 있어 
// 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다." 
// 이말은 땅에서 가장 거리가 먼 두 부분을 구하라는 뜻이다.
// 주어진 인풋값의 크기는 최대 50*50이다. 나이브하게 풀어도 되는 범위이기 때문에
// 땅이라고 판단되는 부분이 보일때마다 BFS로 Flood Fill 해주면 된다.