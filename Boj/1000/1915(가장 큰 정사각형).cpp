#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001], n, m, area;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%1d", &dp[i][j]);
			if(dp[i][j]){
                // 1�ϳ��� �־����� ��츦 ������ ����ó���� �ؾ��Ѵ�.
				area = area ? area : 1;
                // ��ȭ��
				dp[i][j] += min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
				area = max(area, dp[i][j]);
			}
		}
	}
	printf("%d\n", area * area);
}

// ����(DP)
// �־��� ���� ���� ����ū ���簢���� ã������ ��ȭ���� ��� �Ǿ�� �ұ�?
// �����ܷ� �����ѵ� ���� ��ǥ���� ��ء� ���� ���� ���������� ���ذ��� �ȴ�.