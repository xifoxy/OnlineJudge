#include <bits/stdc++.h>
using namespace std;
int a, b;
int gcd(int a, int b) {
	if(a % b == 0) return b;
	return gcd(b, a % b);
}
int main() {
	cin >> a >> b;
	if(b > a) swap(a, b);
	int g = gcd(a, b);
	cout << g << '\n' << a*b / g;
}

// ����(GCD)
// �ּ� ������� (a * b / GCD)�� ��������.