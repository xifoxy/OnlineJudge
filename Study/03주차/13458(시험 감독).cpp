#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 1;
int n;
int d[M];
long long ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> d[i];
    
    int b, c;
    cin >> b >> c;
    ans = n;
    for(int i = 0; i < n; ++i){
        d[i] -= b;
        if(d[i] > 0)
            ans += d[i] % c ? d[i] / c + 1 : d[i] / c;
    }
    cout << ans;
}

// 말하지 않아도 알아요~