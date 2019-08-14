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

// 설명(Kruskal's)
// 크루스칼의 특성을 이해 했으면 문제가 쉽게 풀린다.
// 프림알고리즘은 노드간의 단거리 값들을 연결해가면서 풀지만, 크루스칼은 산발적으로 분산된
// 간선들을 연결해가면서 만든다.
// 문제에서 마을의 도시는 하나이상이라고 지침해놨기 때문에
// 연결된 간선의 갯수가 V - 2가 되면 컴포넌트가 2개가 만들어진다.
// 크루스칼의 기본 문제이니 기본 개념을 숙지하자.