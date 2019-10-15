#include <bits/stdc++.h>
using namespace std;
long long a,b;
int main(){
    cin >> a >> b;
    if(a > b) swap(a, b);
    cout << (b - a + 1) * (a + b) / 2;
}

// 말하지 않아도 알아요~