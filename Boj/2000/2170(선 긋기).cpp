#include <bits/stdc++.h>
using namespace std;
struct info{
    int s, e;
};
info pos[1000001];

// 시작 좌표만 가지고 정렬하면 된다. 이유는 아래에서..
bool cmp(const info &a, const info &b){
    return a.s < b.s;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &pos[i].s, &pos[i].e);
    }

    sort(pos, pos + n, cmp);

    int ans = 0, left, right;
    // INF 값으로 초기화
    left = right = -2e9;
    for(int i = 0; i < n; ++i){
        // 현재 좌표의 끝점보다 다음 좌표의 끝점이 크다면 서로 다른 구역이 되기 때문에
        // 값을 더해주고 좌표를 갱신한다.
        if(right < pos[i].s){
            ans += right - left;

            left = pos[i].s;
        }
        // 끝 좌표는 매번 갱신해도 된다. 항상 큰 값을 유지해야 하기 떄문이다.
        // 그리고 끝 좌표를 정렬 하지 않아도 되는 이유이기도 하다.
        right = max(right, pos[i].e);
    }
    ans += right - left;
    printf("%d\n", ans);
}

// 설명(Sweeping)
// 문제를 보고 가장 먼저 떠오른건 1931(회의실 배정) 문제였다. 그리디함이 해답일것 같아,
// 좌표를 입력받아 시작과 끝이 작은순서로 정렬해서, 시작의 범위와 끝의 범위를 체크해서
// 현재의 끝의 범위보다 큰 경우 현재 범위의 값을 더해주고 범위를 갱신해서 풀었다.
// 풀고보니 아직 공부하지 않은 라인 스위핑이라는 알고리즘이더라..