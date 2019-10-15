#include <bits/stdc++.h>
using namespace std;
string sign, vec;
string ans_max, ans_min;
bool visit[11];
// 합당한지 체크
bool check(char ch, int a, int b){
    if(ch == '<' && a > b) return false;
    if(ch == '>' && a < b) return false; 
    return true;
}
// 재귀
void sol(string &num){
    int sz = num.size();
    // 부등호의 갯수가 3개라면 숫자는 총 4개로 이루어진 조합이어 한다.
    if(sz == sign.size() + 1){
        // 순차적인 조합 특성상 작은 수 부터 큰 수 순서로 조합이 만들어진다.
        if(!ans_min.size()) ans_min = num;
        ans_max = num;
        return;
    }
    for(int i = 0; i <= 9; ++i){
        if(visit[i]) continue;
        if(!sz || check(sign[sz - 1], num.back() - '0', i)){
            visit[i] = true;
            num.push_back(i + '0');
            sol(num);
            num.pop_back();
            visit[i] = false;
        }
    }
}
int main(){
    int n;
    char ch;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> ch;
        sign.push_back(ch);
    }
    sol(vec);
    cout << ans_max << '\n' << ans_min;
}

// 설명(Brute Force, Permutation)
// 숫자의 개수는 10개이다. 부등호의 갯수 + 1 만큼의 조합(숫자길이)을 구해서 답을 구하면된다.
// 조합을 구해놓고 부등호를 비교하기보단, 
// 위치에 들어갈 값이 합당한 식이 만들어질때 재귀를 타도록 짜는게 더 빠르다.