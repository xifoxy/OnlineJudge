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

// 설명(disjoint-set, Union Find)
// disjoint한 집합을 표현하기 위한 자료구조이다.
// 형태는 트리의 형태를 하고 있으며, 트리의 컴포넌트들은 각각 하나의 집합이다.
// 기본문제 이니 만큼 개념숙지를 하고 풀면 된다.