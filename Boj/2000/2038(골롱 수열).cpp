#include <bits/stdc++.h>
using namespace std;
int dp[680000];
int n, sum;
int main() {
	scanf("%d", &n);
	dp[1] = sum = 1;
	if(n == 1) puts("1");
	else for(int i = 2; i <= n; ++i) {
		sum += (dp[i] = 1 + dp[i - dp[dp[i - 1]]]);
		if(sum >= n) {
			printf("%d\n", i);
			break;
		}
	}
}

// ����(Math)
// ��ռ��� ã�ƺ��� �Ѵ�. �̰� ��ã�ƺ��� Ǯ�� Boj���� �����ϰ� ���� ������ ����.