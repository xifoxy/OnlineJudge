#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc, n;
    scanf("%d", &tc);
    for(int t_Case = 1; t_Case <= tc; ++t_Case){
        scanf("%d", &n);
        vector<int> arr(n);
        for(int idx = 0; idx < n; ++idx){
            scanf("%d", &arr[idx]);
        }

        sort(arr.begin(), arr.end());
        int get_Max_Gap = -1;

        for(int idx = 1; idx < n; ++idx){
            get_Max_Gap = max(get_Max_Gap, arr[idx] - arr[idx-1]);
        }
        printf("Class %d\n", t_Case);
        printf("Max %d, Min %d, Largest gap %d\n", arr.back(), arr.front(), get_Max_Gap);
    }
}

// 말하지 않아도 알아요~