#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; ++i){
        string str;
        getline(cin, str);
        if(str[0] >= 'a' && str[0] <= 'z')
            str[0] -= 32;
        cout << str << '\n';
    }
}

// 말하지 않아도 알아요~
// 쉬운 문제지만 물어보는게 명확하다. 한줄을 입력받을 줄 아느냐?
// 버퍼를 비워야 하는 이유를 아느냐.