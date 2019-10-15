#include <bits/stdc++.h>
using namespace std;
string DP[10001];
string getSum(string big, string small){
    string ret;
    // 큰 수의 길이만큼 '0'으로 초기화 해준다.
    ret.resize(big.size(), '0');

    // 뒤집어서 더하는게 길이가 더 늘어났을대 유용하다.
    reverse(big.begin(), big.end());
    reverse(small.begin(), small.end());
    for(int i = 0; i < big.size(); ++i){
        int num = big[i] - '0';
        if(i < small.size())
            num += (small[i] - '0');
        
        // '0'으로 초기화 했기 때문에 더해진 값의 숫자만큼만 값을 조정해주면 된다.
        ret[i] += (num % 10);

        // 10을 초과할 경우.
        if(num >= 10){
            if(i == ret.size() - 1)
                ret.push_back('1');
            else ret[i+1]++;
        }

        // 현재 위치에 들어간 값이 10을 초과할 경우
        if(ret[i] > '9'){
            ret[i] = (ret[i] - '0') % 10 + '0';
            if(i == ret.size() - 1)
                ret.push_back('1');
            else ret[i+1]++;
        }
    }
    // 뒤집어서 다시 반환
    reverse(ret.begin(), ret.end());
    return ret;
}
int main(){
    DP[0] = "0";
    DP[1] = "1";
    for(int i = 2; i <= 10000; ++i){
        DP[i] = getSum(DP[i-1], DP[i-2]);
    }
    for(int i = 0; i < 100; ++i)
        cout << DP[i] << '\n';
}

// 설명(Parsing)
// 그냥 문자열 잘 박살내면 된다...