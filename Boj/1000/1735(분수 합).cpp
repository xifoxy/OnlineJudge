#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	int a, b, c, d, g;
	cin >> a >> b >> c >> d;
	int p = b * d, s = a * d + b * c;
	g = gcd(s, p);
	printf("%d %d\n", s / g, p / g);
}

// ����(GCD)
// �� �м��� ���� ���м�(���̻� �������� �ʴ� �м�)�� ����� �����̴�.
// �и�� ������ �ִ������� ���ؼ� �������.