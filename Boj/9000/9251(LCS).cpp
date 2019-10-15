#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 1;
int dp[M][M];
string str1, str2;
int main(){
    cin >> str1 >> str2;
    for(int i = 1; i < str1.size() + 1; ++i){
        for(int j = 1; j < str2.size() + 1; ++j){
                dp[i][j] = max({
                    dp[i][j - 1], 
                    dp[i - 1][j], 
                    dp[i - 1][j - 1] + (str1[i-1] == str2[j-1])});
        }
    }
    int x = str1.size();
    int y = str2.size();
    cout << dp[x][y] << '\n';
}

// 설명(LCS, DP)
// LCS 기초 알고리즘이다. 모르면 학습부터 하자.