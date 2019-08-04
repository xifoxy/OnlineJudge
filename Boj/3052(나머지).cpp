#include <bits/stdc++.h>
using namespace std;
bool dp[43];
int n, ans;
int main(){
	for(int i = 0; i < 10; ++i){
		scanf("%d", &n);
		dp[n % 42] = true;
	}

	for(int i = 0; i < 42; ++i)
		if(dp[i]) ans++;

	printf("%d\n", ans);
}

// 생략