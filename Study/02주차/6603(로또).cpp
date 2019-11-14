#include <bits/stdc++.h>
using namespace std;
int a[14];
int k;

vector<int> vec;
void permutation(int cur){
    if(vec.size() == 6){
        for(auto &n : vec)
            printf("%d ", n);
        puts("");
        return;
    }

    for(int idx = cur; idx < k; ++idx){
        vec.push_back(a[idx]);
        permutation(idx + 1);
        vec.pop_back();
    }

    return;
}

int main(){
    while(scanf("%d", &k) && k != 0){
        vec.clear();
        for(int idx = 0; idx < k; ++idx){
            scanf("%d", &a[idx]);
        }
        permutation(0);
        puts("");
    }
}

// 설명
// N과 M 시리즈를 풀어보자