#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1e5 + 1;
struct P {
	int x, y, z, idx;
};
struct P2 {
	int u, v, w;
	bool operator <(const P2 &t) {
		return this->w < t.w;
	}
};
bool cmpx(const P &a, const P &b) {
	return a.x < b.x;
}
bool cmpy(const P &a, const P &b) {
	return a.y < b.y;
}
bool cmpz(const P &a, const P &b) {
	return a.z < b.z;
}

P edge[MAX_V];
vector<P2> eg;
int uf[MAX_V];

int find(int a) {
	if(uf[a] == a) return a;
	return uf[a] = find(uf[a]);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].z);
		edge[i].idx = i;
		uf[i] = i;
	}

	sort(edge, edge + n, cmpx);
	for(int i = 0; i < n - 1; ++i)
		eg.push_back({edge[i].idx, edge[i + 1].idx, abs(edge[i].x - edge[i + 1].x)});

	sort(edge, edge + n, cmpy);
	for(int i = 0; i < n - 1; ++i)
		eg.push_back({edge[i].idx, edge[i + 1].idx, abs(edge[i].y - edge[i + 1].y)});

	sort(edge, edge + n, cmpz);
	for(int i = 0; i < n - 1; ++i)
		eg.push_back({edge[i].idx, edge[i + 1].idx, abs(edge[i].z - edge[i + 1].z)});

	sort(eg.begin(), eg.end());

	int cnt = 0, ans = 0;
	for(int i = 0; i < eg.size(); ++i) {
		int a = find(eg[i].u);
		int b = find(eg[i].v);
		if(a != b) {
			uf[a] = b;
			cnt++;
			ans += eg[i].w;
			if(cnt == n - 1) break;
		}
	}

	printf("%d\n", ans);
}

//설명을 적지 않겠다. 다시한번 보는게 내 정신건강에 좋을것 같다.