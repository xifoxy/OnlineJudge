#include <bits/stdc++.h>
using namespace std;

const int M = 101;
int adj[M][M];
int n;
// X를 고정시키고 Y에서 방문 가능한 모든곳을 X배열에 저장한다.
void dfs(int cur, int next){
    adj[cur][next] = 1;
    for(int y = 0; y < n; ++y)
        if(adj[next][y] && !adj[cur][y])
            dfs(cur, y);
}
int main(){
    scanf("%d", &n);
    for(int x = 0; x < n; ++x)
        for(int y = 0; y < n; ++y)
            scanf("%d", &adj[x][y]);


    for(int x = 0; x < n; ++x)
        for(int y = 0; y < n; ++y)
            // x -> y로 갈 수 있다면,
            if(adj[x][y])
                dfs(x, y);

    for(int x = 0; x < n; ++x){
        for(int y = 0; y < n; ++y)
            printf("%d ", adj[x][y]);
        puts("");
    }
}

// 설명
// 예전에 풀때는 무슨말인지 예제가 이해가 안가던 문제였다.

// 방법은 간단하다.
// X배열 에서 좌표Y(Y배열로) 갈수 있는지 체크해주면 된다.