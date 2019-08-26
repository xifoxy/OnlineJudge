#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e6 + 1;
vector<ll> prime;
bool isprime[M];
ll s, e;
int main(){
    scanf("%lld%lld", &s, &e);

    // sqrt함수는 제곱근 즉 정수부분만 취하기 때문에 + 1해줄 필요가 있다.
    // ex) 1, 8이면 2를 반환한다(이해가 가지 않는다면 Sieve of Eratosthenes를 공부해보자.)
    ll mx = sqrt(e) + 1;
    for(ll i = 2; i < mx; ++i){
        if(!isprime[i]){
            prime.push_back(i);
            for(ll j = i * i; j < mx; j+=i)
                isprime[j] = true;
        }
    }

    // 배열의 재활용
    memset(isprime, false, sizeof(isprime));

    for(ll &p : prime){
        ll n = p * p;
        // 시작지점은 S부터이다. 헌데, 나누어 떨어지면 S부터 탐색하면 되지만,
        // 나누어 떨어지지 않으면 나누어 떨어지는 부분부터 탐색해야한다.
        // 걸러내는 방법도 Sieve of Eratosthenes와 비슷한 방식으로 걸러낸다.
        for(ll j = s % n ? (s / n + 1) * n : s; j <= e; j += n){
            isprime[j - s] = true;
        }
    }
    int ans = 0;
    // e-s는 최대 100만이다.
    for(int i = 0; i < e - s + 1; ++i){
        if(!isprime[i])
            ans++;
    }
    printf("%d\n", ans);
}

// 설명(Sieve of Eratosthenes, O(NloglogN))
// 우선 주어진 조건을 보자.
// 1 <= min <= 1e12
// max <= min + 1e6

// 언뜻보면 엄청 커보이는 숫자들이다.
// 하지만 문제에서 "1보다 큰 제곱수로 나누어 떨어지지 않을때" 라는 수식이
// 붙음으로써 문제는 소수의 제곱으로 나누어 떨어지지 않는 수로 바뀌게 된다.

// 그렇다면 구해야 하는 소수의 범위는 어떻게 될까?
// 조건에서 max는 최대 1,000,001,000,000이다. 보기 편하게 백만을 때고 보면
// 1e12 = 1e6 ^ 2 가 된다.
// 즉 구해야할 소수 범위는 1e6까지 이기 때문에 시간복잡도로 봤을때 0.1초도 안걸리게
// 뽑아낼 수 있는 범위가 된다.

// 직접 구해보면 알겠지만 최대범위로 잡아도 소수는 10만개가 되지 않는다.
// 구해진 소수를 토대로 주어진 범위(최대 1e6)만큼의 범위에서 답을 걸러내면 된다.(나머지는 소스주석)