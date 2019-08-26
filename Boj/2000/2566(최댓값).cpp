#include <bits/stdc++.h>
using namespace std;
int ans = -1, x, y, n;
int main(){
    for(int x = 0; x < 9; ++x){
        for(int y = 0; y < 9; ++y){
            scanf("%d", &n);
            if(n > ans){
                x = i + 1;
                y = j + 1;
                ans = n;
            }
        }
    }
    printf("%d\n%d %d\n", ans, x, y);
}

// 쉬어가는 문제. 배열 쓸 필요 없다.