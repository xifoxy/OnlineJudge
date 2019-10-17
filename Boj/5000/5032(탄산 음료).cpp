#include <bits/stdc++.h>
using namespace std;
int main(){
    int e, f, c, ans = 0, sum = 0;
    scanf("%d%d%d", &e,&f,&c);

    sum = e + f;
    while(sum >= c){
        ans += sum / c;
        sum = sum / c + sum % c;
    }
    printf("%d\n", ans);
}

// 무슨 말인가 싶었다.