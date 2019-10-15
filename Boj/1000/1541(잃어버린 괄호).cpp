#include <bits/stdc++.h>
using namespace std;
string str;
int getSum(int start, int end){
    string temp;
    int ret = 0;
    for(int i = start; i < end; ++i){
        if(str[i] == '-' || str[i] == '+'){
            ret += stoi(temp);
            temp.clear();
        } else temp.push_back(str[i]);
    }
    ret += stoi(temp);
    return ret;
}

int main(){
    cin >> str;
    size_t pos = str.find('-');

    int ans = 0;
    if(pos != string::npos){
        ans = getSum(0, pos);
        ans -= getSum(pos + 1, str.size());
    }
    if(pos == string::npos)
        ans = getSum(0, str.size());
    cout << ans << '\n';
}

// 설명(Greedy)
// 한참을 고민했는데 그리디 문제였다... 엿같다
// 문제를 푸는 방법은 -가 나타나는 구간은 전부다 빼주면 된다.

// 그러니까.. 일반화 시켜보면..
// 50 - (1 + 2 + 3 + 4) - (2 + 3 + 4 + 5 + 1) ... 이런 방식이다.
// 자 그럼 이걸 한번 더 줄여보면...
// 첫 - 이후 값들은 전부다 더해서 빼주면 최솟값이 된다.
// 10 - 20 - 30 - 40 + 50 이라는 식은 ==> 10 - (20 + 30 + 40 + 50) 이거랑 같다.
