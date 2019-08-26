#include <bits/stdc++.h>
using namespace std;
int dp[2002];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int num;
		scanf("%d", &num);
		dp[num + 1000]++;
	}

	for(int i = 0; i <= 2000; ++i){
		if(dp[i])
			printf("%d ", i - 1000);
	}
}

// 설명
// 정렬해야할 숫자의 범위가 -1e3 <= N <= 1e3
// 간단하게 2천개짜리 배열을 선언해서 해결이 가능하다.