#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 1;
int n, cnt = 1, tri = 1, ans;
int dp[MAX];
vector<int> triangle{1};
int main() {
	scanf("%d", &n);

    // �ﰢ�� �����ü�� �ױ�(n��° �ﰢ�� ���ϴ� ���� : n(n + 1) / 2)
	while(triangle.back() <= n) {
        // �ﰢ��
		tri += ++cnt;
        // �ﰢ�� �ױ�
		triangle.push_back(triangle.back() + tri);
	}
	fill(&dp[1], &dp[MAX], MAX);
	
    // �޸������̼�
	for(int i = 0; i < triangle.size(); ++i) {
		if(triangle[i] > n) break;
		for(int j = triangle[i]; j <= n; ++j) {
			dp[j] = min(dp[j], dp[j - triangle[i]] + 1);
		}
	}
	printf("%d\n", dp[n]);
}


// ����(DP)
// �ﰢ���� ���� ���ذ� �ʿ��ϴ�.
// �ﰢ���� �����ϰ� ���������� �׾ƿø��� �����ü�� �ϼ��ȴ�.