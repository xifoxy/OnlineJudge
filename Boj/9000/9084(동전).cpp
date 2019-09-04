#include <bits/stdc++.h>
using namespace std;
const int M = 1e4 + 1;
int tc;
int main(){
	scanf("%d", &tc);
	while(tc--){
        // 기저단위
		int dp[M]{1,}, coin[M]{0,};
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &coin[i]);
		}

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < M; ++j){
                // J원을 만들기 위해서 J - coin[i]의 값이 0보다 크거나 같으면 갱신한다.
				if(j - coin[i] >= 0)
					dp[j] += dp[j - coin[i]];
			}
		}
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
}

// 설명(DP)
// 주어진 동전으로 만들 수 있는 돈의 가짓수를 전부 만들면 된다.