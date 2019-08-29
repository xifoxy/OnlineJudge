#include <bits/stdc++.h>
using namespace std;
int h, m, s, ss;
int main(){
    scanf("%d%d%d%d", &h, &m, &s, &ss);
    s += ss;
    m += s / 60; s %= 60;
    h += m / 60; m %= 60;
    h %= 24;
    printf("%d %d %d\n", h, m, s);
}

// 이런거 못풀면 자살해야된다.