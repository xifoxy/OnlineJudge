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
            a.length() + b.length() - 1 > MX.length() ||    // 수를 비교하고도 Overflow가 나오지 않는다면,
                                                            // 두수를 곱했을때의 최소 길이를 검사한다.
            !getOper(a, b, r))                              // 그래도 Overflow가 아니라면 R / B > A에 대해서 검사한다.
        cout << "overflow" << '\n';

    else cout << stoll(a) * stoll(b) << '\n';               // 위 조건을 충족하지 않을시 곰셈한 값을 출력한다.
}

// 설명
// 생각해야 할 조건이 많은 문제이다.
// 오버플로우 조건을 3개 정도로 생각하고 푼것 같다.

// 1. a or b가 r보다 큰 경우
// 2. 길이(a + b - 1)이 r보다 큰 경우
//  **(하나 더 생각 해야 할건 길이(3+3)은 6이 될수도 5가 될수도 있다 ex. 100*100 = 10,000, 999*999 = 998,001)
// 3. 나누기 연산을 통해서 정수부 취하기

// 자세한건 소스에