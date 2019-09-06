#include <bits/stdc++.h>
using namespace std;
int d[501], n, L;
int dp[501];
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		d[u] = v;
		L = max(L, max(u,v));
	}

	int ans = 0;
	for(int i = 1; i <= L; ++i) {
		for(int j = i + 1; j <= L; ++j){
			if(d[i] < d[j] && dp[i] >= dp[j]) dp[j]++;
		}
		ans = max(ans, dp[i]);
	}
	printf("%d\n", n - ans);
}

// ����(LIS, DP)
// �������� �������� �����鼭 �ִ��� ���� ����Ǿ�� �ϴ� ���¸� ���ؾ� �Ѵ�.
// �� ���캸�� �˰����� LIS�� �Ȱ���.
// �����ؾ��Ұ� �־��� N�� ������ �ƴ϶�°Ͱ�, �������� ������� ���� �κе� �ִٴ°��̴�.
// ���� �������� ����� �������� 8�� ������ ������ 10�����̴�.