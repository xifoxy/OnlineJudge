#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e10;
vector<ll> ans;
vector<ll> vec[10];
int main(){
    // 0���� 9������ �����ϴ� �� �̴�.
    for(int i = 0; i < 10; ++i){
        ans.push_back(i);
        vec[0].push_back(i);
    }
    
    ll k = 1;
    for(int i = 1; i < 10; ++i){
        k *= 10;

        // ���ϰ��� �ϴ� ������ ���̺��� ���ڸ� ª�� ���� ���� ���� ���ذ���.
        for(ll j = k; j < k * 10; j += k){
            int sz = vec[i - 1].size();
            for(int z = 0; z < sz; ++z){
                // ���� ���ڸ� 10���� ��������, ���ڸ� ª�� ���ڰ� ũ�ų� ���ٸ�?
                // ex) j = 90, vec[i-1][z] = 9�� ��� 99�� �����ϴ� ���� �ƴϴ�.
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

// ����(Brute Force, Dp)
// �� ������ �ٽ��� ������ �����ϴ� ���� ������ �ִٴ� ���̴�.
// 9876543210 ������ �����ϴ¼��� �������� ����.
// �̰� ���� �ٷ� �����ܰ��� �����̸� ������ ���� ���ذ��� �ȴ�.