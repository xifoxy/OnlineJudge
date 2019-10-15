#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int>::iterator it;
int main(){
    int n, it;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int num;
        scanf("%d", &num);
        it = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
        if(it == arr.size()) arr.push_back(num);
        else arr[it] = num;
    }
    printf("%d\n", arr.size());
}

// 설명(추가예정)