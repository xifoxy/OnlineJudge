#include <bits/stdc++.h>
using namespace std;
int a[1000001], n, m;
long long l, r = 10000000000, mid, sum;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	while(l + 1 < r) {
		mid = (l + r) / 2;
		sum = 0;
		for(int i = 0; i < n; ++i) {
			if(a[i] > mid) {
				sum += a[i] - mid;
				if(sum >= m) break;
			}
			
		}
		if(sum >= m) l = mid;
		else r = mid;
	}
	cout << l;
}

// ����
// ���̵��� �����ڸ���� ����.
// 0.5�ʳ� ���ͼ� �� ���� �ҽ��� �ôµ� ���ݴ� ���� ����ȭ ����� �ֱ⿡ �����ߴ�.
// �ٽ��� ���ؾ� �ϴ� �������� �� ���� �߸��� ���� ���� ������ ���ߴ°��̴�.
// �̰� ��ǲ�����Ͱ� 100������ �Ǳ� ������ �����غ��� ���� ȿ������ ����� �ȴ�.
// �ڸ��� ���̺��� ������� �ڸ��� �ʴ� �κ��� �� ���캸��.