#include <bits/stdc++.h>
using namespace std;
int ans;
void hexadecimal(string &num){
    num = num.substr(2);
    reverse(num.begin(), num.end());

    int x = 16;
    for(int i = 0; i < num.size(); ++i){
        int n;
        if(num[i] >= 'a' && num[i] <= 'f')
            n = 10 + num[i] - 'a';
        else n = num[i] - '0';
        ans += n * x / 16;
        x *= 16;
    }
}
void octaldecimal(string &num){
    num = num.substr(1);
    reverse(num.begin(), num.end());

    int x = 8;
    for(int i = 0; i < num.size(); ++i){
        ans += (num[i] - '0') * (x / 8);
        x *= 8;
    }
}
int main(){
    string input;
    cin >> input;

    if(input.front() == '0'){
        if(input[1] == 'x') hexadecimal(input);
        else octaldecimal(input);
        cout << ans;
    } else cout << input;
}

// 말하지 않아도 알아요~