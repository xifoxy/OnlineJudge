#include <bits/stdc++.h>
using namespace std;
const int M = 1e4 + 1;
int d[M], n, num;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> num;
        d[num]++;
    }

    for(int i = 0; i < M; ++i){
        for(int j = 0; j < d[i]; ++j)
            cout << i << '\n';
    }
}

// 설명
// 메모리제한이 8MB 이고, 수의 범이가 1 <= N <= 1e4 이기 때문에
// 카운팅 소트로 풀어야 된다.