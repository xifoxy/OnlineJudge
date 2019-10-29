#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 4000;
bool isprime[M];
bool palindrome(string num){
    string temp = num;
    reverse(num.begin(), num.end());
    return temp == num;
}
int main(){
    for(long long i = 2; i * i < M; ++i){
        if(isprime[i] == false){
            for(long long j = i * i; j < M; j +=i){
                isprime[j] = true;
            }
        }
    }
    isprime[1] = true;
    int n; scanf("%d", &n);
    for(int i = n; i <= M; ++i){
        if(isprime[i] == false && palindrome(to_string(i))){
            printf("%d\n", i);
            break;
        }
    }
}

// 설명(Sieve)
// 뒤집어서 같으면 팰린드롬이다.
// 주의해야 할 점은.. 1 <= N <= 1e6
// 1!