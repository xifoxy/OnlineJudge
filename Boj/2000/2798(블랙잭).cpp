#include <bits/stdc++.h>
using namespace std;
int Card[101];
int main(){
	int n, m, sum = 0;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%d", &Card[i]);
	}

	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			for(int k = j + 1; k < n; ++k){
				int sum_C = Card[i] + Card[j] + Card[k];
				if(sum_C <= m){
					sum = max(sum, sum_C);
				}
			}
		}
	}
	printf("%d\n", sum);
}

// 설명(Brute Force)
// 카드 3개의 합이 <= M이 되는 최대값을 구하면 된다.
// 주어진 카드 개수 N은 <= 100 이기 때문에 완탐으로 해결 가능하다.