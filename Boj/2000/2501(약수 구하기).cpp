#include <bits/stdc++.h>
int n, k, cnt, ans;
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i){
        if(k == cnt) break;
        if(n % i == 0){
            ++cnt;
            ans = i;
        }
    }
    printf("%d\n", cnt == k ? ans : 0);
}

// 이런거 못풀면 자살해야된다.