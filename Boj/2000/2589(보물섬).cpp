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

// ����(BFS)
// ������ ���� "������ ���� ���� �ִ� �Ÿ��� �̵��ϴµ� �־� 
// ���� �� �ð��� �ɸ��� ���� �� ���� ������ �����ִ�." 
// �̸��� ������ ���� �Ÿ��� �� �� �κ��� ���϶�� ���̴�.
// �־��� ��ǲ���� ũ��� �ִ� 50*50�̴�. ���̺��ϰ� Ǯ� �Ǵ� �����̱� ������
// ���̶�� �ǴܵǴ� �κ��� ���϶����� BFS�� Flood Fill ���ָ� �ȴ�.