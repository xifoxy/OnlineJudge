#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1e5 + 1;
struct P {
	int u, v, w;
	bool operator<(const P &a) {
		return this->w < a.w;
	}
};
vector<P> edge;
int uf[MAX_V];

int find(int a) {
	if(uf[a] == a) return a;
	return uf[a] = find(uf[a]);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	edge.resize(m);
	for(int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edge[i] = {u - 1, v - 1, w};
	}
	for(int i = 0; i < n; ++i)
		uf[i] = i;
	sort(edge.begin(), edge.end());

	int ans = 0, cnt = 0;
	for(int i = 0; i < edge.size(); ++i) {
		int a = find(edge[i].u);
		int b = find(edge[i].v);
		if(a != b) {
			uf[b] = a;
			ans += edge[i].w;
			++cnt;
		}
		if(cnt == n - 2) break;
	}
	printf("%d\n", ans);
}

// ����(Kruskal's)
// ũ�罺Į�� Ư���� ���� ������ ������ ���� Ǯ����.
// �����˰����� ��尣�� �ܰŸ� ������ �����ذ��鼭 Ǯ����, ũ�罺Į�� ��������� �л��
// �������� �����ذ��鼭 �����.
// �������� ������ ���ô� �ϳ��̻��̶�� ��ħ�س��� ������
// ����� ������ ������ V - 2�� �Ǹ� ������Ʈ�� 2���� ���������.
// ũ�罺Į�� �⺻ �����̴� �⺻ ������ ��������.