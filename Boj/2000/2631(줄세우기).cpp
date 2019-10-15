#include <bits/stdc++.h>
using namespace std;
int arr[201];
int dp[201];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
        dp[i] = 1;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
    }

    int getMax = -1;
    for(int i = 0; i < n; ++i){
        getMax = max(dp[i], getMax);
    }

    printf("%d\n", n - getMax);
}

// 설명(LIS)
// 한참을 고민했다. 그런데 LIS기초 문제였다 ㅋㅋ