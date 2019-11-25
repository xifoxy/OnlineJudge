#include <bits/stdc++.h>
using namespace std;

int d[51];
int n, s;
int main(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> d[i];
    
    cin >> s;

    for(int i = 0; i < n && s; ++i){

        int mElem = -1;
        int idx = 0;
        // 현재위치 i부터 i + s + 1까지 탐색해서 가장 큰 숫자를 찾는다.
        for(int j = i; j < i + s + 1 && j < n; ++j){
            if(mElem < d[j]){
                idx = j;
                mElem = d[j];
            }
        }

        // 밀어 주는거 구현하는게 귀찮아서 rotate함수를 썼다.
        rotate(d + i, d + idx, d + idx + 1);

        // 밀고 나서 이동시킨칸만큼 S를 줄여준다.
        s = s - (idx - i);;
    }

    for(int i = 0; i < n; ++i){
        cout << d[i] << ' ';
    }
}

// 설명
// "연속된 두 개의 원소만 교환할 수 있다." 라는 말은 즉, 버블 소트를 떠올릴 수 있다.
// S가 엄청 크다고 쫄지 말고 N의 범위에 주목해야 한다. 1 <= N <= 50

// N번째 자리에 있는 수를 제일 앞으로 보내려면 N - 1만큼의 교환 횟수가 필요하다.
// ex) 1 2 3 4 5
// 1 2 3 5 4
// 1 2 5 3 4
// 1 5 2 3 4
// 5 1 2 3 4

// 그러니 Current_Index + S의 범위 안에 있는 가장 큰 숫자를 가져오면 된다.