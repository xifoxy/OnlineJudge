#include <bits/stdc++.h>
using namespace std;
bool visit[101];
int ans;
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int pos;
        scanf("%d", &pos);
        if(visit[pos]) ans++;
        visit[pos] = true;
    }
    printf("%d\n", ans);
}

// 말하지 않아도 알아요~