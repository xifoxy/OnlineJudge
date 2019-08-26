#include <bits/stdc++.h>
using namespace std;
int tc;
int main(){
	scanf("%d", &tc);
	while(tc--){
		int n, d[1001] = {0,};
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &d[i]);
		
		int ans = -9999;
		for(int i = 0; i < n; ++i){
			int sum = 0;
			for(int j = i; j < n; ++j){
				sum += d[j];
				ans = max(ans, sum);
			}
		}
		printf("%d\n", ans);
	}
}

// 설명
// 완탐 문제이다.
// -1e3 <= N <= 1e3 이라는 것만 주의하자.