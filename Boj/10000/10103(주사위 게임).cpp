#include <bits/stdc++.h>
using namespace std;
int a, b;
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int aa, bb;
        cin >> aa >> bb;
        if(aa == bb) continue;
        if(aa > bb) b += aa;
        else a += bb;
    }
    cout << 100 - a << '\n' << 100 - b;
}

// 말하지 않아도 알아요~