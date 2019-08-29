#include <bits/stdc++.h>
int sum, in, out, ans;
int main(){
    for(int i = 0; i < 10; ++i){
        scanf("%d%d", &out, &in);
        sum += in - out;
        ans = std::max(ans, sum);
    }
    printf("%d\n", ans);
}

// 이런거 못풀면 자살해야된다.