#include <bits/stdc++.h>
using namespace std;
int d[501][501], n, ans;
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= i; ++j) {
			cin >> d[i][j];
			if(i) {
				// 현재 위치가 제일 왼쪽이라면? 내려 올수 있는 길은 0번째 인덱스 밖에 없다.
				if(!j) d[i][j] += d[i - 1][j];
				// 현재 위치가 제일 오른쪽이라면? 내려 올수 있는 길은 j-1 밖에 없다.
				else if(j == i) d[i][j] += d[i - 1][j - 1];
				else d[i][j] += max(d[i - 1][j - 1], d[i - 1][j]);
			}
			ans = max(ans, d[i][j]);
		}
	}
	cout << ans << '\n';
}

// 설명(DP)
// 조금 단순하게 접근할 필요가 있다.
// dp[n][1]로 내려 올 수 있는 dp[n-1]은? dp[n-1][0]과 dp[n-1][1] 밖에 없다.