#include <bits/stdc++.h>
using namespace std;
int d[1001], n;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &d[i]);

    sort(d, d + n);
    for(int i = 0; i < n; ++i)
        printf("%d\n", d[i]);
}

// 말하지 않아도 알아요~