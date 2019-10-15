#include <bits/stdc++.h>
using namespace std;
int arr[10];
int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        for(int i = 0; i < 10; ++i){
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + 10);
        printf("%d\n", arr[7]);
    }
}

// 말하지 않아도 알아요~
// 만약 범위가 커진다면? heap