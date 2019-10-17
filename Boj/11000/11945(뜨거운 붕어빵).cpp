#include <bits/stdc++.h>
using namespace std;
int main(){
    string temp;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        reverse(temp.begin(), temp.end());
        cout << temp << '\n';
    }
}

// 말하지 않아도 알아요~