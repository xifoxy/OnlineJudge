#include <bits/stdc++.h>
using namespace std;
int a,b;
void sol(int n){
    if(n == 0) return;
    int mod = n % b;
    sol(n / b);
    if(mod < 10) printf("%d", mod);
    else printf("%c", 'A' + mod - 10);
}
int main(){
    scanf("%d%d",&a,&b);
    sol(a);
}

// 설명
// 깡구현이다. 2745번 진법 변환은 자릿수의 각 자릿수의 값을 구해줘서 풀었었다.
// 진법 변환2 는 10진법으로 주어진 자연수를 가지고 K진법으로 교체하는 작업을 해야 하기 때문에,
// 나머지 연산을 이용해서 자릿수 별로 값을 구해 출력했다.