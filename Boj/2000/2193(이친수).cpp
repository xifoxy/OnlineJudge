#include <bits/stdc++.h>
using namespace std;
long long d[91];
int n;
int main() {
	d[1] = 1;
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i)
		d[i] = d[i - 1] + d[i - 2];

	printf("%lld\n", d[n]);
}

//����
//������ Ǭ���ӿ��� �ұ��ϰ� ���� int���� ����ٴ°� �������� ���� Ʋ�ȴ�.
//���� �׷����� �� �� ������
//������ D[N] = D[N - 1] + D[N - 2] �̴�