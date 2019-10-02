#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9;
int dp[202][202];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);

    // ���� �ϳ��� ���� �� �ִ� ����� ��
	for(int i = 0; i <= n; ++i) {
		dp[1][i] = 1;
	}
	
	for(int i = 2; i <= k; ++i) {
		for(int j = 0; j <= n; ++j) {
			for(int l = 0; l <= n; ++l) {
                // ���� i - 1���� �Ἥ ���� j��� ���ڰ� �����Ҷ�
                // j + l �� n���� ������ �����Ѵ�.
				if(dp[i - 1][j] && j + l <= n) {
					dp[i][j + l] = (dp[i][j + l] + dp[i - 1][j]) % MOD;
				}
			}
		}
	}
	printf("%d\n", dp[k][n]);
}


#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9;
int dp[202][202];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
    
	for(int i = 0; i <= n; ++i) {
		dp[1][i] = 1;
	}
	for(int i = 2; i <= k; ++i) {
		dp[i][0] = 1;
		for(int j = 1; j <= n; ++j) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	printf("%d\n", dp[k][n]);
}

// ����(DP)
// ù ��° �ҽ��� ���̺��� �ҽ���.
// �� ��° �ҽ��� ����ȭ�� �ߴ�.
// Ǯ� ���� ���� �˰����� ���� ���´� ���������� ���·� ���������.