#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    int n, nn;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> nn >> str;
        str.erase(str.begin() + nn - 1);
        cout << str << '\n';
    }
}

// 말하지 않아도 알아요~