#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	n = n / 100 * 100;
	if(n % m) {
		m = m - n % m;
		if(m < 10) printf("0%d\n", m);
		else printf("%d\n", m);
	} else puts("00");
}

// ����(Math)
// �־��� ���ڴ� 100 <= N <= 2e9�̰� ���� ���ڴ� 1 <= F <= 100 �̴�
// ���� �� �ΰ� �ϸ�, ���ڰ� �󸶰� �Ƶ� ���� �� ���� ���ڸ��� �ּڰ����� �����
// ������ �������Ը� ����� �ȴٴ� ���̴�.