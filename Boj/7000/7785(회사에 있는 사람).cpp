#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    set<string> s;
    cin >> n;
    string Name, Status;
    for(int i = 0; i < n; ++i){
        cin >> Name >> Status;
        if(Status == "enter")
            s.insert(Name);
        else s.erase(Name);
    }

    
    for(set<string>::reverse_iterator it = s.rbegin(); it != s.rend(); ++it){
        cout << *it << '\n';
    }
}

// 말하지 않아도 알아요~
// 정렬, BST, Hash 등등 많은 방법이 있다.