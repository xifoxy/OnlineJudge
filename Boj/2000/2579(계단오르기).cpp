#include <bits/stdc++.h>
using namespace std;
int n, a[301], d[301];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	d[1] = a[1];
	d[2] = d[1] + a[2];

	for(int i = 3; i <= n; ++i) {
		if(d[i] < d[i - 2] + a[i])
			d[i] = d[i - 2] + a[i];
		if(d[i] < d[i - 3] + a[i] + a[i - 1])
			d[i] = d[i - 3] + a[i] + a[i - 1];
	}
	cout << d[n] << '\n';
}

#include <bits/stdc++.h>
using namespace std;
int a[10001], n, d[10001];
int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	d[1] = a[1]; d[2] = d[1] + a[2];

	for(int i = 3; i <= n; ++i) {
		d[i] = d[i - 1];
		if(d[i] < d[i - 2] + a[i])
			d[i] = d[i - 2] + a[i];
		if(d[i] < d[i - 3] + a[i] + a[i - 1])
			d[i] = d[i - 3] + a[i] + a[i - 1];
	}
	cout << d[n];
}

// ����
// ���� ��ܿ�����, �Ʒ��� ������ �ý� ���¹ٿ� ���� ��ȭ���� ������
// ���̽� ������ ���� �ٸ���. 
// 2�� ���� ���Ժο� ���� D[i] = D[i - 1]
// �װ� �������� �����ϴ� "������ ����� �ݵ�� ��ƾ� �Ѵ�"
// �̰� �ٽ��̴�. ������ �ý��� ���������� ���� �ʴ��� �ִ��� ���� ������ ������
// ��� ������� ������ ����� ������ ��ƾ� �Ѵٴ� ���������� �ʿ��ϴ�.