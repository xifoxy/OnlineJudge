#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1e6 + 1;
int n, m, uf[MAX_V];
int find(int a) {
	if(uf[a] == a) return a;
	uf[a] = find(uf[a]);
	return uf[a];
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	uf[b] = a;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		uf[i] = i;

	for(int i = 0; i < m; ++i) {
		int cmd, u, v;
		scanf("%d%d%d", &cmd, &u, &v);
		if(!cmd) merge(u, v);
		else {
			u = find(u);
			v = find(v);
			printf("%s\n", u == v ? "YES" : "NO");
		}
	}
}

// ����(disjoint-set, Union Find)
// disjoint�� ������ ǥ���ϱ� ���� �ڷᱸ���̴�.
// ���´� Ʈ���� ���¸� �ϰ� ������, Ʈ���� ������Ʈ���� ���� �ϳ��� �����̴�.
// �⺻���� �̴� ��ŭ ��������� �ϰ� Ǯ�� �ȴ�.