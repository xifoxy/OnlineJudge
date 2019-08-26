#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 2e5 + 1;
int un[MAX_V];
struct P { int u, v, w; };
int find(int a) {
	if(un[a] < 0) return a;
	return find(un[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return false;
	un[b] = a;
	return true;
}
int n, m;
int main() {
	
	while(scanf("%d%d", &n, &m)) {
		if(n == m && !n) break;
		vector<P> Edge;
		Edge.resize(m);
		long long ans = 0;
		int cnt = 0;
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			Edge[i] = {u, v, w};
			ans += w;
		}
		sort(Edge.begin(), Edge.end(), [](P &a, P &b) {
			return a.w < b.w;
		});
		fill(un, un + n, -1);
		for(int i = 0; ; ++i) {
			if(merge(Edge[i].u, Edge[i].v)) {
				++cnt;
				ans -= Edge[i].w;
				if(cnt == n - 1) break;
			}
		}
		printf("%lld\n", ans);
	}
}

//문제를 잘 읽자. 어려운게 아닌데 좀 해멘다..