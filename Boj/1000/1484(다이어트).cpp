#include <bits/stdc++.h>
int n;
bool cmp;
int main() {
	scanf("%d", &n);
	long long l = 1, r = 1;
	while(r <= 50001) {
		if(r * r - l * l == n) {
			printf("%lld\n", r);
			cmp = true;
		}
		if(r * r - l * l >= n) ++l;
		else ++r;
	}
	if(!cmp) puts("-1");
}

// ����
// ������ ���� �����ִ�.
// ���� ������ Cur, ���� ������ Bef
// Cur*Cur - Bef*Bef == n �� �ɶ����� ����ϸ�ȴ�.