#include <bits/stdc++.h>
using namespace std;
int z[41], o[41];
int tc, a;
int main() {
	z[0] = o[1] = 1;
	scanf("%d", &tc);
	for(int i = 2; i <= 40; ++i) {
		z[i] = z[i - 1] + z[i - 2];
		o[i] = o[i - 1] + o[i - 2];
	}
	while(tc--) {
		scanf("%d", &a);
		printf("%d %d\n", z[a], o[a]);
	}
}

//DP�⺻������.
//�Ǻ���ġ N�� ���� N - 1�� N - 2�� ȣ��ȴ�.
//�׷� 1���� �׾ư��� �ȴ�.