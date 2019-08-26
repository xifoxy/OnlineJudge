#include <bits/stdc++.h>
using namespace std;
int d[3], ans;
int main(){
    int tc; scanf("%d", &tc);
    while(tc--){
        scanf("%d%d%d", &d[0], &d[1], &d[2]);
        sort(d, d + 3);
        if(d[0] == d[1] && d[1] == d[2])
            ans = max(ans, d[0] * 1000 + 10000);
        else if(d[0] == d[1] || d[1] == d[2])
            ans = max(ans, (d[0] == d[1] ? d[0] : d[1]) * 100 + 1000);
        else ans = max(ans, d[2] * 100);
    }
    printf("%d\n", ans);
}

// 생략