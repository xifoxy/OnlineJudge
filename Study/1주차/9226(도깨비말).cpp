#include <bits/stdc++.h>
using namespace std;

bool isvowel[26];
int main(){
    string str;
    isvowel['a' - 'a'] = isvowel['e' - 'a'] = isvowel['i' - 'a'] = isvowel['o' - 'a'] = isvowel['u' - 'a'] = true;
    while(cin >> str && str != "#"){
        int index = str.front() - 'a';
        while(!isvowel[index]){
            str.push_back(str.front());
            str.erase(0, 1);
            index = str.front() - 'a';
        }
        cout << str + "ay" << '\n';
    }
}

// 설명
// 주어진 단어의 첫 글자가 모음이 아니라면, 단어의 제일 뒤로 보내면 된다.