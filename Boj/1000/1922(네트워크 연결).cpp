#include <bits/stdc++.h>
using namespace std;
struct P {
	int u = -1, v = -1, w = 0;
};

const int MAX_V = 1e3 + 1;
int Union[MAX_V];
int find(int a) {
	if(Union[a] < 0) return a;
	return Union[a] = find(Union[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return false;
	Union[b] = a;
	return true;
}

vector<P> Edge;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	Edge.resize(m);
	for(int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		Edge[i] = {u, v, w};
	}
	sort(Edge.begin(), Edge.end(), [](P a, P b) {
		return a.w < b.w;
	});

	int ans = 0, cnt = 0;
	fill(Union, Union + n, -1);
	for(int i = 0; ; ++i) {
		if(merge(Edge[i].u, Edge[i].v)) {
			ans += Edge[i].w;
			++cnt;
			if(cnt == n - 1) break;
		}
	}
	printf("%d\n", ans);
}

// ����(MST, Minimum Spanning Tree, Union find)
// �ִܰŸ� �����߿� �̷��� �Ⱥ��� �̰� ���� ���Ҹ� �ΰ� �;��µ� 
// �����ϰ��� ������ ���ϴ°����� �˰� ����..
// ������ ������ ����Ŭ�� ������ �ʵ��� �ϸ鼭 �������� ����°��̴� �̰� MST�� �����̴�.