#include <bits/stdc++.h>
using namespace std;
int n, x, y, cnt;
void sol(int r, int c, int sz){
	if(x == r && y == c) {
        cout << cnt << '\n';
        return;
    }

    if(r <= x && r + sz > x && c <= y && c + sz > y){
        sz >>= 1;
        sol(r, c, sz);
        sol(r, c + sz, sz);
        sol(r + sz, c, sz);
        sol(r + sz, c + sz, sz);
    } else{
        cnt += (sz * sz);
    }
}
int main(){
	cin >> n >> x >> y;
	sol(0, 0, 1 << n);
} 

// 설명(Recursion)
// 잘 쪼개고 더하면 된다. 더 이상의 설명이 불필요한것 같다.