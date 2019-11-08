#include <bits/stdc++.h>
using namespace std;
bool cmpSz(string &a, string &r){
    // A의 길이가 길면 Overflow다.
    if(a.size() != r.size()) return a.size() > r.size();

    // 각 자릿수를 비교해서 A가 큰게 나오면 Overflow다.
    for(int i = 0; i < a.size(); ++i){
        if(a[i] != r[i]) return a[i] > r[i];
    }
    return false;
}
bool getOper(string &a, string &b, long long r){
    // 앞의 과정을 거쳤으면 두 수는 R의 범위 안에 있다.
    long long aa = stoll(a);
    long long bb = stoll(b);

    // R / B >= A인지 검사를 하기 위해 나눈다.
    long long oper = r / bb;

    // 나누어 떨어지지 않는다면 소수부가 존재하니,
    // R / B의 정수부를 취해 A보다 작으면 Overflow다.
    if(r % bb){
        return oper >= aa;
    }

    // 나누어 떨어질 경우 두 수가 같거나, 혹은
    // R / B가 큰 경우 두 수의 곰셈은 R의 범위 안에 있다.
    return oper == aa ? true : oper > aa;
}
int main(){
    string a, b;
    long long r = 0, aa, bb;
    cin >> a >> b >> r;

    string MX = to_string(r);
    if(b > a) swap(a,b);
    
    if(b[0] == '0') cout << '0' << '\n';                    // 두 수 중 작은수가 0이면 0을 출력한다.

    else if(cmpSz(a, MX) || cmpSz(b, MX) ||                 // (A, B)를 R과 비교한다.
            !getOper(a, b, r))                              // Overflow가 아니라면 R / B > A에 대해서 검사한다.
        cout << "overflow" << '\n';

    else cout << stoll(a) * stoll(b) << '\n';               // 위 조건을 충족하지 않을시 곰셈한 값을 출력한다.
}

// 설명
// 생각해야 할 조건이 많은 문제이다.
// 오버플로우 조건을 2개 정도로 생각하고 푼것 같다.

// 1. a or b가 r보다 큰 경우
// 2. 나누기 연산을 통해서 정수부 취하기

// 자세한건 소스에