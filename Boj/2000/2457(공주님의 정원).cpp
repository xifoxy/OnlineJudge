#include <bits/stdc++.h>
using namespace std;
struct info{
    int s, e;
};
int n;

vector<info> dp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    dp.reserve(n);

    for(int i = 0; i < n; ++i){
        int m, d, em, ed;
        cin >> m >> d >> em >> ed;
        dp.push_back({m * 100 + d, em * 100 + ed});
    }


    // 시작 날짜가 작은순서로 정렬한다.
    sort(dp.begin(), dp.end(), [](const info &a, const info &b){
        return a.s < b.s;
    });

    int cnt = 0;
    // 0인 이유는 3월 1일 전에 꽃을 심어야 3월1일에 꽃을 볼 수 있는 경우를 생각해야한다.
    int Next = 0;
    // 3월 1일부터 11월 30일까지니까 시작날짜를 3월1일로 맞춘다.
    int Cur = 301;
    bool flag = true;
    for(int i = 0; i < n; ++i){
        // 심을 수 있는 꽃이 없거나 11월30일을 넘어서는 날짜가 갱신되면 멈춘다.
        if(!flag || Cur > 1130) break;
        flag = false;
        for(int j = i; j < n; ++j){
            // 현재 날짜보다 시작날짜가 큰 경우 멈춘다.
            if(Cur < dp[j].s) break;

            // 비교군의 날짜가 종료일자 보다 작은 경우 갱신한다.
            if(Next < dp[j].e){
                Next = dp[j].e;
                flag = true;
                i = j;
            }
        }

        // 종료날짜 갱신
        Cur = Next;
        cnt++;
    }

    cout << (Cur > 1130 ? cnt : 0) << '\n';
}

// 설명
// 소스를 여러번 갈아엎은 문제다.
// 처음에는 Month, Day를 따로 입력받아서 정렬해서 이용하려고 실컷 만들었는데..
// 너무 난잡해서 그냥 Month에다가 100을 곱해버렸다.(그러면 101~1231 로 날짜를 표기할 수 있다.)