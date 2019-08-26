#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int ret(int a, int b) {
	// �ڿ����� 0 ������ 1�̴�.
	if(b == 0) return 1;
	int t = ret(a, b / 2);
	int r = 1LL * t * t % c;
	// Ȧ���� ���
	// ex) ¦���� �ɰ��� Ȧ���� ���� ��� 10^10 10^18
	if(b % 2) r = 1LL * r * a % c;
	return r;
}
int main() {
	cin >> a >> b >> c;
	cout << ret(a, b) << '\n';
}


// ����(Divide ans Conquer)
// A�� B�� ���� ���� �˰�ʹ�. �� ���� A�� B�� �����Ѵٴ� ���̴�.
// Brute Force�� Ǯ�⿡�� A,B,C�� ũ�Ⱑ 21���̾ �ʹ� ũ��.
// �̰� 2�ʿ� �ذ� �ϱ� ���ؼ� ���������� �̿��ؼ� ���� �ؾ��� �ʿ䰡 �ִ�.
// ex) 10^10000 = 10^5000 * 10^5000 �̴�