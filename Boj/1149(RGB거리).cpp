#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 1;
int n;
int d[3][MAX];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d%d", &d[0][i], &d[1][i], &d[2][i]);

	for(int i = 1; i <= n; ++i) {
        // ���� �������̸� ����̳� �Ķ����� �ּڰ���
		d[0][i] += min(d[1][i - 1], d[2][i - 1]);
        // ���� ����̸� �������̳� �Ķ����� �ּڰ���
		d[1][i] += min(d[0][i - 1], d[2][i - 1]);
        // ���� �Ķ����̸� �������̳� ����� �ּڰ���
		d[2][i] += min(d[0][i - 1], d[1][i - 1]);
	}
	printf("%d\n", min(d[0][n], min(d[1][n], d[2][n])));
}

// ����
// ���� ���� ���ӵ��� �ʰ� �������縸 �����ָ� �ȴ�.