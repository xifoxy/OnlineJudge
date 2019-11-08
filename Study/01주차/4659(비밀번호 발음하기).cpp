#include <bits/stdc++.h>
using namespace std;
string str;
bool isvowel[26];
int d[21];
int main(){
    isvowel['a' - 'a'] = isvowel['e' - 'a'] = isvowel['i' - 'a'] = isvowel['o' - 'a'] = isvowel['u' - 'a'] = true;

    while(cin >> str && str != "end"){
        
        bool isacceptable = true;
        int cnt = 0;
        memset(d, 0, sizeof(d));
        for(int i = 0; i < str.size() && isacceptable; ++i){
            d[i]++;
            int cur = str[i] - 'a';
            if(isvowel[cur]) cnt++;
            if(!i) continue;

            int bef = str[i-1] - 'a';
            if(isvowel[bef] == isvowel[cur]){
                if(d[i - 1] == 2){
                    isacceptable = false;
                    break;
                }
                if(str[i] == str[i - 1] && (str[i] == 'e' || str[i] == 'o'))
                    d[i]++;
                else if(str[i] != str[i-1])
                    d[i]++;
                else {
                    isacceptable = false;
                    break;
                }
            }
        }

        cout << '<' + str + '>' + " is ";
        if(cnt && isacceptable)
            cout << "acceptable.";
        else cout << "not acceptable.";
        cout << '\n';
    }
}

// 설명
// 뭐 따로 필요한게 없다, 그냥 혐오스러운 조건들을 '잘' 구현해주면 된다.
// "비요뜨를 죽여버리고 싶다."