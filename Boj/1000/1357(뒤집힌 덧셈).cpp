#include <bits/stdc++.h>
using namespace std;
int a, b;
int f(int n) {
	int ret = 0;
	while(n) {
		ret *= 10;
		ret += n % 10;
		n /= 10;
	}
	return ret;
}
int main() {
	scanf("%d%d", &a, &b);
	printf("%d\n", f(f(a) + f(b)));
}

// ����
// �� ���ڸ� ����� �����ذ� �ٽ� ����� �������.