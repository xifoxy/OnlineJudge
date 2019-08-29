#include <bits/stdc++.h>
using namespace std;
int n, m, a[10001];
long long r = 10000000000, ans, mid, l, cnt;
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	while(l < r) {
		mid = (l + r) / 2;
		cnt = 0;
		for(int i = 0; i < n; ++i)
			cnt += (a[i] / mid);
		if(m <= cnt) {
			l = mid + 1;
			ans = max(ans, mid);
		} else r = mid;
	}
	cout << ans << '\n';
}


// ����
// �������� �������.
// �̺� Ž������ Ǯ��Ǵµ� left�� right�� ������ �� �������Ѵ�.
// ������ ���� right�� ���� intmax������ ����༭ ���� Ʋ�ȴ�.
// ���ذ��� 1���̶� �ּ� 10��� ũ�� ����ִ°� ���Űǰ��� ����.
// �ݺ��� �ӿ� ������
// l + 1 < r, l = mid�� l < r, l = m + 1�̳� �Ȱ���.