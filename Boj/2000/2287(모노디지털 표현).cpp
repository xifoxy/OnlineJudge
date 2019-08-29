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
            // i번 가해진 연산과 j번 가해진 연산의 합이 8이 넘으면 안된다.
            if(i + j > 8) continue;
            for(auto &num1 : vec[i]){
                for(auto &num2 : vec[j]){
                    // 4칙연산
                    int temp[4] = {num1 * num2, num1 / num2, num1 + num2, abs(num1 - num2)};
                    for(int temp_idx = 0; temp_idx < 4; ++temp_idx){
                        int num = temp[temp_idx];

                        // 0은 연산의 횟수만 늘려줄 뿐이기에 후보군에 넣을 필요가 없다.
                        // stl map은 해당 인덱스를 탐색하는것 만으로도 초기화가 이루어진다.
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


// 설명(DP)
// 우선 문제의 조건을 살펴보면, 찾는 수의 조건은 1 <= a <= 32e3 이고 연산의 최대 길이는 8이다(55는 2로 본다).
// Brute Force로만 풀기엔 경우의 수가 유동적이기에 Memoization을 적용할 필요가 있다.

// 정답을 저장시킬 자료구조를 제한할 필요가 있다.
// 답은 확인해야할 숫자는 32e3보다 작지만, 답을 도출하는 과정에서 32e3을 훨씬 넘기때문에
// 평범한 배열로 답을 체크하기엔 메모리 소모가 너무 심하다.
// 답 도출을 위한 범위는 크나, 큰 범위에 비해 도출되는 수의 개수는 작으니 균형잡힌 이진트리를 사용한다.