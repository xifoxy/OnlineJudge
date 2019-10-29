#include <bits/stdc++.h>
using namespace std;
vector<int> dp[10];
bool isprime(int num){
    for(long long i = 2; i * i <= num; ++i){
        if(num % i == 0) return false;
    }
    return true;
}
int main(){
    dp[1] = {2,3,5,7};
    
    int len;
    scanf("%d", &len);

    for(int i = 2; i <= len; ++i){
        for(auto &prime : dp[i - 1]){

            for(int k = 0; k <= 9; ++k){
                if(isprime(prime * 10 + k)){
                    dp[i].push_back(prime * 10 + k);
                }
            }
        }
    }

    for(auto &prime : dp[len])
        printf("%d\n", prime);
}

// 설명
// 처음에 어떻게 풀지 막막했다.
// 주어진 메모리가 4MB이기 때문에 Sieve로는 불가능하다.
// 한참 고민하다가 힌트를 얻은 부분은
// "원 수가 소수이면서, 왼쪽부터 1~N(소수의 길이)자리 까지 모두 소수인 수"가 힌트였다.
// N자리 수가 소수가 될려면 N - 1자리 수도 소수가 되어야 하기 때문에 1자리 부터 N자리 까지
// 차곡차곡 채워 나가면 된다.