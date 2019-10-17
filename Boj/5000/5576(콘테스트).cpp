#include <bits/stdc++.h>
using namespace std;
int sol(){
    vector<int> vec(10);
    for(int i = 0; i < 10; ++i)
        scanf("%d", &vec[i]);
    sort(vec.begin(), vec.end());
    return vec[7] + vec[8] + vec[9];
}
int main(){
    printf("%d ", sol());
    printf("%d\n", sol());
}

// 말하지 않아도 알아요~