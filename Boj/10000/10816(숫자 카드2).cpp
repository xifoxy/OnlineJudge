#include <bits/stdc++.h>
using namespace std;
int a[500001], n, m, num, l, r, mid, ans;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < 500001; ++i) a[i] = 999999999;
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	sort(a, a + n);
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d", &num);
		l = 0; r = n;
		while(l <= r) {
			mid = (l + r) / 2;
			if(a[mid] < num) l = mid + 1;
			else r = mid - 1;
		}
		ans = l;
		l = 0; r = n;
		while(l <= r) {
			mid = (l + r) / 2;
			if(a[mid] <= num) l = mid + 1;
			else r = mid - 1;
		}
		ans = r - ans + 1;
		printf("%d ", ans);
	}
}

//����
//�̺�Ž���� ������ �ο�ٿ��� ���۹ٿ�尡 �ʿ��ϴ�.
//�ο�ٿ�� : ���ĵ� ���ڿ��� ���ϴ� ������ ù��° ��ġ
//���۹ٿ�� : ���ĵ� ���ڿ��� ���ϴ� ������ ������ ��ġ
//�ε����� �����ϴ� ������ ������ �������� �ʾƼ� �迭 ��ü�� ����� ū���� �ʱ�ȭ �ߴ�.
//�̺�Ž���� ������ �ο�ٿ��, ���۹ٿ�� ������ ������ ���� �ɰ� ����.