#include <bits/stdc++.h>
using namespace std;
int n;
int ans, x, Max;
int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x;
        ans += x;
        Max = max(Max, x);
    }

    cout << ans + Max * (n > 1 ? n - 2 : 0);
}

// 설명
// A와 B가 AB인지 BA인지 설명이 없다.