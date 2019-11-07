#include <bits/stdc++.h>
using namespace std;
int n, waiting, ans;
int main(){
    cin >> n >> waiting;

    ans = waiting;
    for(int i = 0; i < n; ++i){
        int in, out;
        cin >> in >> out;

        waiting += in - out;
        if(waiting < 0) {
            puts("0");
            return 0;
        }
        ans = max(ans, waiting);
    }
    
    cout << ans << '\n';
}

// 설명
// 문제만 잘 읽으면 풀수 있다.

// 3
// 2(Waiting)
// 2 3(0~1분)
// 2 3(1~2분)
// 4 1(2~3분)

// 웨이팅 중인 차량은 2대이고,
// 0~1분 Waiting += 2(in) - 3(out) ==> 1
// 1~2분 Waiting += 2(in) - 3(out) ==> 0
// 2~3분 Waiting += 4(in) - 1(out) ==> 3(정답)