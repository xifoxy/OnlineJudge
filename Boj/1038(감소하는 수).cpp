#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e10;
vector<ll> ans;
vector<ll> vec[10];
int main(){
    // 0부터 9까지는 감소하는 수 이다.
    for(int i = 0; i < 10; ++i){
        ans.push_back(i);
        vec[0].push_back(i);
    }
    
    ll k = 1;
    for(int i = 1; i < 10; ++i){
        k *= 10;

        // 구하고자 하는 숫자의 길이보다 한자리 짧은 숫를 토대로 답을 구해간다.
        for(ll j = k; j < k * 10; j += k){
            int sz = vec[i - 1].size();
            for(int z = 0; z < sz; ++z){
                // 현재 숫자를 10으로 나눴을때, 한자리 짧은 숫자가 크거나 같다면?
                // ex) j = 90, vec[i-1][z] = 9일 경우 99는 감소하는 수가 아니다.
                if(vec[i - 1][z] >= j / 10) break;
                vec[i].push_back(j + vec[i - 1][z]);
                ans.push_back(j + vec[i - 1][z]);
            }
        }
    }

    int n, sz = ans.size() - 1;
    scanf("%d", &n);
    if(n > sz) puts("-1");
    else printf("%lld\n", ans[n]);
}

// 설명(Brute Force, Dp)
// 이 문제의 핵심은 마지막 감소하는 수가 정해져 있다는 것이다.
// 9876543210 다음의 감소하는수는 있을수가 없다.
// 이걸 토대로 바로 이전단계의 숫길이를 가지고 답을 구해가면 된다.