#include <bits/stdc++.h>
using namespace std;
int dp[17], d[17], c[17], n;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d %d", d + i, c + i);
	}

	for(int i = n; i > 0; --i) {
		int next = i + d[i];
		if(next > n + 1) dp[i] = dp[i + 1];
		else dp[i] = max(dp[i + 1], dp[next] + c[i]);
	}
	printf("%d\n", dp[1]);
}

//����
//Ǯ� �Ｚ���� �߿� ������ DP������.
//��Ž���ε� ���������� ����ϰ� Ǯ��� �ϴϱ� DP�� Ǯ����.
//ó�� ������ �������� ���� ��¥���� Ǫ�ϱ� DP���� �������� �ʾ� ����� �ߴ�.
//����� �ڿ������� Ǯ�� ���� ����ϰ� ���´�.