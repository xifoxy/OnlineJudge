#include <bits/stdc++.h>
using namespace std;
const int M = 1e9;
int x, y, win_rate, l, r = M, ans = M + 1;
int avg(int total, int win) {
	return 1LL * win * 100 / total;
}
int main() {
	scanf("%d%d", &x, &y);
	win_rate = avg(x, y);
	while(l <= r) {
		int mid = (l + r) / 2;

        // �����ٸ� �� ���� ���ڸ� ã�´�.
		if(win_rate < avg(x + mid, y + mid)) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
        // ������ �ʴ� �ٸ� �� ū ���ڸ� ã�´�.
	}
	printf("%d\n", ans > M ? -1 : ans);
}

// ����(Binary Search)
// �̺�Ž������ �����ϰ� Ǯ���� �����̴�.
// ������ ���丷�� �ٿ����� O(logN)�̸� �ȴ�.