#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string str){
    int it = 0;
    int rit = str.size() - 1;
    for(; it < rit; ++it, --rit){
        if(str[it] != str[rit])
            return false;
    }
    return true;
}
int main(){
    string str, temp = "";
    cin >> str;
    
    int sz = str.size();
    for(int i = 0; i < sz; ++i){
        if(i) temp = str[i - 1] + temp;
        if(ispalindrome(str + temp)){
            cout << str.size() + i << '\n';
            break;
        }
    }
}

// 설명(Parsing)
// DP로도 풀리는것 같은데 생각을 안해봐서 잘 모르겠다.

// 원본 문자열과 뒤집은 문자열이 같으면 팰린드롬이라고 부른다. 이를 응용해서..
// 주어진 문자열의 접두사를 전부 구해서 뒤집는다.

// ex) ABCDE
// A, BA, CBA, DCBA, EDCBA
// 이를 원본 문자열 뒤에 붙여서 팰린드롬인지 검사를 하면 된다.
// ABCDE A      false
// ABCDE BA     false
// ABCDE CBA    false
// ABCD E DCBA  true