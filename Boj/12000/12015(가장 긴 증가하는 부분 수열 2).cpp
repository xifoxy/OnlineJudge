#include <bits/stdc++.h>
using namespace std;
const int M = 1e6+1;
int arr[M], n;
int main(){
    vector<int> ans;

    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);

        int it = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
        if(it == ans.size())
            ans.push_back(arr[i]);
        else ans[it] = arr[i];
            
    }

    printf("%d\n", ans.size());
}

// 2352 반도체 설계와 같은 문제이다.