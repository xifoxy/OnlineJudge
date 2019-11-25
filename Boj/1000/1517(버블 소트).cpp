#include <bits/stdc++.h>
using namespace std;

const int M = 5e5;
int t[M], d[M];
int n;
long long sol(int Start, int End){
    if(Start == End) return 0;
    int Mid = (Start + End) / 2;

    // 최소단위까지 쪼갠다.
    long long ret = sol(Start, Mid) + sol(Mid + 1, End);

    int Left = Start, Right = Mid + 1, idx = 0;

    // Mid를 기준으로 배열을 좌, 우로 나눈다.
    while(Left <= Mid || Right <= End){

        // 1. 좌측의 원소만 남았거나,
        // 2. 우측의 원소보다 작거나 같을 경우
        // 원소의 이동은 없다.
        if(Left <= Mid && (Right > End || t[Left] <= t[Right]))
            d[idx++] = t[Left++];
        
        // 우측의 원소가 좌측의 원소보다 크거나 같을 경우
        // 버블 소트의 이동 공식을 이용하면 된다.
        // 1083소트 문제를 참조하자.
        else{
            ret += (Mid - Left + 1);
            d[idx++] = t[Right++];
        }
    }
    for(int i = Start; i <= End; ++i)
        t[i] = d[i - Start];

    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> t[i];
    }

    cout << sol(0, n - 1) << '\n';
}

// 설명
// 정렬해야 하는 범위가 1 <= N <= 5e5 라서, O(NlogN)의 시간복잡도가 되는 정렬을 이용해서 풀어야 한다.
// θ(NlogN), O(N^2)인 일반적인 Quick Sort는 최악의 케이스가 주어졌다는 가정하에는 시간이 부족하다.
// 그럼 변형된 Quick Sort 혹은 Merge Sort를 이용해야 하는데, 
// Bubble Sort의 특성상 Merge Sort로 풀어야 한다.

// Quick Sort는 변형이 되었다고 해도 Pivot을 기준으로 원소들을 좌, 우 로 보내버리기에 이동횟수를
// 세기에는 제법 난잡한 형태를 띈다.

// 하지만 Merge Sort는 우측에 있는 원소를 좌측으로 보낼때 Bubble Sort의 형태를 띄게 된다.
// 그러니 이를 이용해서 풀면 된다.