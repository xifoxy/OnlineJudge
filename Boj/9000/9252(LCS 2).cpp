#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 1;
int dp[M][M];
string str1, str2;
void sol(int x, int y){
    if(dp[x][y] == 0) return;
    if(dp[x][y] == dp[x-1][y]) sol(x-1,y);
    else if(dp[x][y] == dp[x][y-1]) sol(x,y-1);
    else{
        sol(x-1,y-1);
        // str1[x-1] or str2[y-1]
        cout << str1[x - 1];
    }
}
int main(){
    cin >> str1 >> str2;
    for(int i = 1; i < str1.size() + 1; ++i){
        for(int j = 1; j < str2.size() + 1; ++j){
            // 당황하지 말라, max(1, max(2,3)) 과 같은 구문이다.
            dp[i][j] = max({
                dp[i][j - 1], 
                dp[i - 1][j], 
                dp[i - 1][j - 1] + (str1[i-1] == str2[j-1])});
        }
    }
    int x = str1.size();
    int y = str2.size();
    cout << dp[x][y] << '\n';
    sol(x,y);
    
    cout << '\n';
    // 직접 출력해보세요.
    // for(int i = 0; i < str1.size() + 1; ++i){
    //     for(int j = 0; j < str2.size() + 1; ++j){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

// 설명(LCS, DP, BackTracking)
//     0 1 2 3 4 5  
//   0 C A P C A K
// 0 0 0 0 0 0 0 0
// A 0 0[1]1 1 1 1
// C 0 1 1 1[2]2 2
// A 0 1 2 2 2[3]3
// Y 0 1 2 2 2 3 3
// K 0 1 2 2 2 3[4]
// P 0 1 2 3 3 3 4
// 값이 변하는 위치를 잘 살펴보자. LCS를 공부했으면 왜 이런 값이 나오는지 알 수 있다.
// 결론은 값이 변하는 위치가 공통부분 수열이 증가 하는 부분이다.
// 그러니 여기서 필요한 테크닉은 역추적이다.