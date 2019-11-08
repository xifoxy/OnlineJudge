#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    while(getline(cin, str) && str != "#"){
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == ' ')
                cout << "%20";
            else if(str[i] == '!')
                cout << "%21";
            else if(str[i] == '$')
                cout << "%24";
            else if(str[i] == '%')
                cout << "%25";
            else if(str[i] == '(')
                cout << "%28";
            else if(str[i] == ')')
                cout << "%29";    
            else if(str[i] == '*')
                cout << "%2a";
            else cout << str[i];
        }
        puts("");
    }
}

// 설명
// 차트에 나오는 문자가 나올때 마다 인코딩 시키면 된다.