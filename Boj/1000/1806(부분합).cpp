#include <bits/stdc++.h>
using namespace std;
const int MX = 100001;
int a[MX], n, m, ans = MX;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	int l = 0, r = 0, sum = 0;
	while(r <= n) {
		if(sum >= m) {
			ans = min(ans, r - l);
			sum -= a[l++];
		} else sum += a[r++];
	}
	printf("%d\n", ans == MX ? 0 : ans);
}

// ����
// ������ �� 2�� �ٸ��� �ʴ�.
// ��, ���� ���� ��쵵 �����ؾ��Ѵ�.