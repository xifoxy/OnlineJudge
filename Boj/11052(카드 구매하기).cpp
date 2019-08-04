#include <iostream>
#include <algorithm>
using namespace std;
int d[1001], n;
int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> d[i];
	for(int i = 2; i <= n; ++i) {
		int l = 1, r = i - 1;
		while(l <= r) {
			d[i] = max(d[i], d[l] + d[r]);
			++l, --r;
		}
	}
	cout << d[n];
}

#include <cstdio>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
int d[1001], a[1001], n;
int main() {
	scanf("%d", &n); REP(i, n) scanf("%d", a + i + 1);
	FOR(i, 1, n + 1) FOR(j, 1, i + 1) if(d[i] < d[i - j] + a[j])
		d[i] = d[i - j] + a[j];
	printf("%d\n", d[n]);
}

//�������� �ؾ �Ǹ��ϱ��� �������µ� �̸��� �ٲ����.
//���� �̹��� Ǭ���̰� �Ʒ��� ���� �ҽ���.
//�⺻���� Ž�������� ����ϴ�.