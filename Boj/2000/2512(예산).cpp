#include <bits/stdc++.h>
using namespace std;
const int M = 1e4 + 1;
int budget[M], n, sum;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &budget[i]);
        // 1번의 경우를 생각해서 요구 예산을 다 합산한다.
        sum += budget[i];
    }

    int l = 0, r = 2e9, max_budget;
    scanf("%d", &max_budget);

    // 1번의 경우 가장 큰 값 반환
    if(max_budget >= sum){
        sum = 0;
        for(int i = 0; i < n; ++i)
            sum = budget[i] > sum ? budget[i] : sum;
        printf("%d\n", sum);

    // 2번의 경우
    } else{ 
        while(l + 1 < r){
            // 가능한 수치를 찾는다.
            int mid = (1LL * l + r) / 2;
            sum = 0;
            for(int i = 0; i < n; ++i){
                // 분배시킬 예산보다 요구된 예산이 작을 경우
                if(mid > budget[i]){
                    sum += budget[i];

                // 분배시킬 예산보다 요구된 예산이 큰 경우
                } else sum += mid;
                
                // 예산 분배중 총 예산을 넘어설 경우 중지
                if(sum > max_budget) break;
            }

            // 총 예산보다 분배예산이 작거나 같을 경우와 넘을 경우
            if(sum <= max_budget) l = mid;
            else r = mid;
        }
        printf("%d\n", l);
    }
}

// 설명(Binary Search)
// 문제를 제대로 읽지 않아서 한번 틀렸다.
// 문제에서 주어진 조건은 예정된 총 예산 예산보다, 요구된 예산의 합이 작거나 같을 시
// 요구된 예산만을 분배해줘야 한다.

// 한마디로
// 5개의 도시에서
// 1 10 1 15 1 이라고 요청을 했고 준비된 총 예산이
// 100일 경우
// 1 10 1 15 1 만큼만 분배해주면 된다는 뜻이다.
// 답은 15를 출력하면 된다(배정된 예산 최댓값).

// 답을 구하기 위해 두가지의 방법을 이용했다.
// 1. 주어지 총 예산보다, 요구한 총 예산이 작을 경우
// 2. 총 예산보다 요구한 예산이 클 경우

// 1번의 경우 값이 들어올때 전부다 더해줘서 총 예산과 요구된 총 예산의 
//     크기를 비교해서 가장 큰 값을 출력하면 된다.

// 2번의 경우 이분탐색으로 요구된 수치를 찾아가야한다.