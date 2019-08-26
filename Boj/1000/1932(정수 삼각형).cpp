#include <bits/stdc++.h>
using namespace std;
int d[501][501], n, ans;
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= i; ++j) {
			cin >> d[i][j];
			if(i) {
				// ���� ��ġ�� ���� �����̶��? ���� �ü� �ִ� ���� 0��° �ε��� �ۿ� ����.
				if(!j) d[i][j] += d[i - 1][j];
				// ���� ��ġ�� ���� �������̶��? ���� �ü� �ִ� ���� j-1 �ۿ� ����.
				else if(j == i) d[i][j] += d[i - 1][j - 1];
				else d[i][j] += max(d[i - 1][j - 1], d[i - 1][j]);
			}
			ans = max(ans, d[i][j]);
		}
	}
	cout << ans << '\n';
}

// ����(DP)
// ���� �ܼ��ϰ� ������ �ʿ䰡 �ִ�.
// dp[n][1]�� ���� �� �� �ִ� dp[n-1]��? dp[n-1][0]�� dp[n-1][1] �ۿ� ����.