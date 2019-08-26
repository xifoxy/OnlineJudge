#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100][100], n;
ll dp[100][100];
ll sol(int x, int y) {
	if(x >= n || y >= n) return 0;
	if(x == n - 1 && y == n - 1) return 1;
	ll &ret = dp[x][y];
	if(ret != -1) return ret;
	ret = 0;
	int jp = a[x][y];
	ret += sol(x + jp, y) + sol(x, y + jp);
	return ret;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			cin >> a[i][j];
	}
	memset(dp, -1, sizeof(dp));
	cout << sol(0, 0) << '\n';
}

// ����
// �� �ڵ��� �ٽ��� �湮�� ���� 0���� �ʱ�ȭ �Ѵٴ� ���̴�.
// ������ �湮�� ������ �ϴ¼��̴�.
// �������� �Ұ������� ������ �׾ư��� �����
// �Լ��� ȣ���Ҷ� �ش� ��ǥ�� ���� ���ϵ��� �����ϸ� �ȴ�.
// ���� ������ ������ ����� ���� 0�� ��ȯ�ϰ�,
// D[N - 1][N - 1] �� ������������ 1�� ��ȯ�ؼ� ���� ���ذ���.
// �׷� D[0][0]���� �湮�� �� �ִ� ���� ���̵��� �Ǿ� �ִ�.