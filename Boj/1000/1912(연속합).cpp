#include <bits/stdc++.h>
using namespace std;
int n, a[100001], d[100001], ans = -9999;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	for(int i = 1; i <= n; ++i) {
		d[i] = max(a[i], d[i - 1] + a[i]);
		ans = max(d[i], ans);
	}
	cout << ans << '\n';
}

//����
//Input���� ������ �����ϱ⶧���� ������ ���ϸ鼭 �����ϸ� ���� ���� �� ����.
//������ ������ D[i-1]������ A[i]�� Ŭ���� �ִٴ°� ��������.