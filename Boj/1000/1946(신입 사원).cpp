#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 1;

struct info{
    int a,b;
};

int n, t;
info d[M];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> d[i].a >> d[i].b;
        
        sort(d, d + n, [](const info &a, const info &b){
            return a.a < b.a;
        });

        int ans = 1;
        // 1차 시험이 1등인 사람의 2차 시험 점수를 cmp에 넣는다.
        int cmp = d[0].b;
        // 여기서 i 는 1차시험의 등수가 되겠다.(0~n-1)
        for(int i = 1; i < n; ++i){
            // 현재 cmp의 등수보다 높은 등수가 나온다면
            // 그 사람은 회사에 선발될 수 있는 사람이다.
            if(d[i].b < cmp)
                ans++, cmp = d[i].b;
        }
        cout << ans << '\n';
    }
}

// 설명
// 테케 이해가 안되서 한참 고민했던 문제다.
// 일단 테스트 케이스는 등수를 나타낸다.
// 3 2 면 1차시험은 3등 2차시험 2등이라는 말이다.

// 문제 조건에 동차가 없고, 1,2차 시험 모두 뒤떨어지는 사람은 떨어진다고 했으니
// 1차 시험을 오름차순으로 정렬하고 2차 시험을 가지고 비교를 해가면서 구하면 된다.