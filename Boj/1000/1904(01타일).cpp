#include <iostream>
using namespace std;
int d[1000001], n;
int main() {
	d[1] = d[0] = 1;
	cin >> n;
	for(int i = 2; i <= n; ++i) {
		d[i] = (d[i - 1] + d[i - 2]) % 15746;
	}
	cout << d[n] << '\n';
}

// ����
// ���� �����غ��� �Ǻ���ġ �����̴�.
// ��ģ���� ������ ����.