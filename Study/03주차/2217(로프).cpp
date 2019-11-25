#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 1;
int d[M], n;    
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &d[i]);

    sort(d, d + n);

    int ans = 0;
    for(int i = n - 1; i >= 0; --i){
        ans = max(ans, d[i] * (n - i));
    }
    printf("%d\n", ans);
}

// 설명
// 정렬하고, 가장 강한 로프부터 감당할 수 있는 무게를 구해간다.
// ex) 9 5 1
// 9 * 1, 5 * 2, 1 * 3
// 왜 큰것부터 하는지 알겠죠?