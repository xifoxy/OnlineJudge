#include <bits/stdc++.h>
int main(){
    long long n, m;
    scanf("%lld %lld", &n, &m);
    n = std::abs(n - m);
    printf("%lld\n", n);
}

// 생략