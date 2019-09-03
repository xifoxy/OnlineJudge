#include <iostream>
using namespace std;
const int MOD = 1e6;
const int CYCLE = MOD / 10 * 15;
int f[CYCLE] = {0,1};
long long n;
int main(){
    cin >> n;
    for(int i = 2; i < CYCLE; ++i)
        f[i] = f[i-1]+f[i-2],f[i]%=MOD;
    cout << f[n%CYCLE];
}

// 말하지 않아도 알아요~