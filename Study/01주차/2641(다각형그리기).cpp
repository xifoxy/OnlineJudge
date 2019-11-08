#include <bits/stdc++.h>
using namespace std;
char change(char ch){
    if(ch == '4') return '2';
    if(ch == '2') return '4';
    return ch == '1' ? '3' : '1';
}
void input(int n, string &ret){
    for(int i = 0; i < n; ++i){
        cin >> ret[i];
    }
}
bool compare(int n, string &vec, string &org){
    for(int i = 0; i < vec.size(); ++i){
        if(vec == org) return true;
        vec.push_back(vec.front());
        vec.erase(0, 1);
    }
    return false;
}
int main(){
    int n, tc;
    cin >> n;
    
    string org, temp, vec;  
    vector<string> ans;
    org.resize(n);
    temp = vec = org;
    input(n, org);

    cin >> tc;
    while(tc--){
        input(n, vec);
        temp = vec;
        bool check = compare(n, vec, org);
        if(!check){
            for(int i = 0; i < n; ++i)
                vec[i] = change(vec[i]);

            reverse(vec.begin(), vec.end());
            check = compare(n, vec, org);
        }

        if(check) ans.push_back(temp);
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < n; ++j)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
}

// 설명
// 도형을 그리는데 있어서 정방향(시계 방향) 역방향(시계 반대 방향)이 있다고 하자.
// 같은 정방향으로 그려진 도형이라면, 도형을 그리는 시작 위치만 잘 조절해주면 답을 도출할 수 있다.

// 그렇다면 역방향은?
// 역방향은 한번 뒤집으면 된다. 그러니까.. ex. 상 = 하, 좌 = 우
// 이렇게 서로 대치되는 방향으로 값을 바꿔서 주어진 순서를 리버스 함수로 뒤집어서 비교하면 된다.

// 예제를 살펴 보자.
// 원본 : [1 4 1 1 4 3 3 3 2 2]
// 시작 : [
// 끄읕 : ]

// case1 : 3 2 2 1 4 1 1 4 3 3
// 3 2 2] [1 4 1 1 4 3 3 <= 이렇게 하면 답이 된다

// case2 : 4 4 1 1 1 2 3 3 2 3 <= 이건 첫번째 문자열을 하나씩 뒤로 보내봐도 답이 안나온다.
// 2 2 3 3 3 4 1 1 4 1 <= 방향값 대칭값으로 변환
// [1 4 1 1 4 3 3 3 2 2] <= 리버스 답 도출