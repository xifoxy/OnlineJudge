#include <bits/stdc++.h>
using namespace std;

int h, m, hh, mm;
int main(){
    cin >> h >> m;
    h = (h % 30) * 12;
    cout << (h == m ? "O" : "X");
}

// 설명
// 단순한 수학문제이다.
// 12시간 즉 360도를 12로 나누면 시간당 30도가 된다.
// 그러니 나머지 연산을 0~30을 만들어 주고,
// 이 수에 12를 곱한게 분이 되는지 체크를 하면 된다.

// 12를 곱하는 이유는,