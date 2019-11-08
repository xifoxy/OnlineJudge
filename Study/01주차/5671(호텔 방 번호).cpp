#include <bits/stdc++.h>
using namespace std;
bool ispossible(string str){
    sort(str.begin(), str.end());
    for(int i = 1; i < str.size(); ++i)
        if(str[i] == str[i-1])
            return false;
    return true;
}
int main(){
    int l, r;
    while(cin >> l && !cin.eof()){
        int cnt = 0;
        cin >> r;
        for(; l <= r; ++l){
            if(ispossible(to_string(l)))
                ++cnt;
        }
        cout << cnt << '\n';
    }
}

// 설명
// 우선 End Of File(EOF)에 대해 알아야 한다.
// 그리고 범위안에 있는 숫자를 문자열로 만들어 정렬해서 검사하면 된다.