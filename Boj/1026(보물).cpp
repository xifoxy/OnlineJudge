#include <bits/stdc++.h>
using namespace std;
int a[50], b[50];
int n;
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + n, greater<int>());
	int sum = 0;
	for(int i = 0; i < n; ++i)
		sum += a[i] * b[i];
	cout << sum;
}

// ����(Sort)
// ���������� �迭 B�� ������ ���� ����� �Ѵ�..����
// �׷��� �׳� �����ϸ� �ȴ�.
// �ι迭�� �ϳ��� ������������, �ϳ��� ������������ �����ϰ� ���ϸ� �ȴ�.