#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 1;
int d[M], n;    
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &d[i]);

    sort(d, d + n);

    int ans = d[0];
    for(int i = 1; i < n; ++i){
        d[i] += d[i-1];
        ans += d[i];
    }
    printf("%d\n", ans);
}

// 설명
// 문제에 나와있다
// 오른차순으로 정렬하고 더해주면 답이다.