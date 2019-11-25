#include <bits/stdc++.h>
using namespace std;

int d[1001];
int n, l;
int main(){
    cin >> n >> l;

    for(int i = 0; i < n; ++i)
        cin >> d[i];
    
    sort(d, d + n);

    
    int len = d[0];
    int ans = 1;

    for(int i = 0; i < n; ++i){
        if(d[i] >= len + l){
            len = d[i];
            ans++;
        }
    }
    
    cout << ans << '\n';
}

// 설명
// 잘 붙여주면 된다.