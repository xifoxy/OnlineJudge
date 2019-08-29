#include <bits/stdc++.h>
using namespace std;
int ans = -1, xx, yy, n;
int main(){
    for(int x = 0; x < 9; ++x){
        for(int y = 0; y < 9; ++y){
            scanf("%d", &n);
            if(n > ans){
                xx = x + 1;
                yy = y + 1;
                ans = n;
            }
        }
    }
    printf("%d\n%d %d\n", ans, xx, yy);
}

// �ڻ콺