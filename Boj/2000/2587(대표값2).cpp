#include <bits/stdc++.h>
using namespace std;
int d[5], sum;
int main(){
    for(int i = 0; i < 5; ++i){
        scanf("%d", &d[i]);
        sum += d[i];
    }
    sort(d, d + 5);
    printf("%d\n%d\n", sum / 5, d[2]);
}

// 이런거 못풀면..