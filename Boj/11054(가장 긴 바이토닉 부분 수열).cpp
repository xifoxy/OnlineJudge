#include <bits/stdc++.h>
using namespace std;
int n, a[1001], d[1001], d2[1001], ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i], d[i] = d2[i] = 1;

	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(a[i] < a[j])
				d[j] = max(d[i] + 1, d[j]);
		}
		int idx = n - i - 1;
		for(int j = n - i - 2; j >= 0; --j) {
			if(a[idx] < a[j])
				d2[j] = max(d2[idx] + 1, d2[j]);
		}
	}

	for(int i = 0; i < n; ++i)
		ans = max(d[i] + d2[i], ans);

	cout << ans - 1 << '\n';
}


//����
//���� �κм����� �տ�������, �׸��� �ڿ��� ���� ����� �ȴ�.
//�׷� �տ������� �����ϴ� �޸������̼��� ���������� �ɰ��̰�.
//�ڿ��� ����°��� �����ϴ� �޸������̼��� �ɰ��̱� �����̴�.
//�ΰ��� �޸������̼� ���� �ִ밡 �Ǵ°� ���� �ȴ�.