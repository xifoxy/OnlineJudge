#include <bits/stdc++.h>
using namespace std;
const int M = 1e3+1;
int arr[M];
int pre[M];
int dp[M];
int n;
// 재귀로 출력하기 싫으면 Stack을 써도 된다.
void print(int pos){
    if(!pos) return;
    int next = pre[pos];
    print(next);
    printf("%d ", arr[pos]);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &arr[i]);
        dp[i] = 1;
    }

    int ans = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < i; ++j){
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                ans = max(dp[i], ans);
                // 인덱스 저장
                pre[i] = j;
            }
        }
    }

    printf("%d\n", ans);
    for(int i = n; i > 0; --i){
        if(ans == dp[i]){
            print(i);
            break;
        }
    }
}

// 설명(LIS, Prev Array) 
// 우선 LIS를 구현할줄 알아야 한고(11053 문제 참조),
// 갱신 될때마다 Prev배열에 Index를 담아주면 된다.