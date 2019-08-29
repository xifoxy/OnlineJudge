#include <bits/stdc++.h>
using namespace std;
const int M = 32e3 + 1;
map<int, int> dp;
vector<int> vec[10];
int main(){
    int K;
    scanf("%d", &K);

    int t = 0;
    for(int i = 1; i <= 8; ++i){
       t = t * 10 + K;
       vec[i].push_back(t);
       dp[t] = i;
    }

    for(int i = 1; i <= 8; ++i){
        for(int j = 1; j <= 8; ++j){
            // i�� ������ ����� j�� ������ ������ ���� 8�� ������ �ȵȴ�.
            if(i + j > 8) continue;
            for(auto &num1 : vec[i]){
                for(auto &num2 : vec[j]){
                    // 4Ģ����
                    int temp[4] = {num1 * num2, num1 / num2, num1 + num2, abs(num1 - num2)};
                    for(int temp_idx = 0; temp_idx < 4; ++temp_idx){
                        int num = temp[temp_idx];

                        // 0�� ������ Ƚ���� �÷��� ���̱⿡ �ĺ����� ���� �ʿ䰡 ����.
                        // stl map�� �ش� �ε����� Ž���ϴ°� �����ε� �ʱ�ȭ�� �̷������.
                        if(num && (dp[num] == 0 || dp[num] > i + j)){
                            vec[i + j].push_back(num);
                            dp[num] = i + j;
                        }
                    }
                }
            }
        }
    }
    int tc, num;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &num);
        if(dp[num]) printf("%d\n", dp[num]);
        else puts("NO");
    }
}


// ����(DP)
// �켱 ������ ������ ���캸��, ã�� ���� ������ 1 <= a <= 32e3 �̰� ������ �ִ� ���̴� 8�̴�(55�� 2�� ����).
// Brute Force�θ� Ǯ�⿣ ����� ���� �������̱⿡ Memoization�� ������ �ʿ䰡 �ִ�.

// ������ �����ų �ڷᱸ���� ������ �ʿ䰡 �ִ�.
// ���� Ȯ���ؾ��� ���ڴ� 32e3���� ������, ���� �����ϴ� �������� 32e3�� �ξ� �ѱ⶧����
// ����� �迭�� ���� üũ�ϱ⿣ �޸� �Ҹ� �ʹ� ���ϴ�.
// �� ������ ���� ������ ũ��, ū ������ ���� ����Ǵ� ���� ������ ������ �������� ����Ʈ���� ����Ѵ�.