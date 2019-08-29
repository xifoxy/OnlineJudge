#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORM(i,a,b) for(int i = (a); i > (b); --i)
#define REPM(i,n) FORM(i,n,0)
#define FORS(i,a,b) for(int i = (a); (b{i}); ++i)
#define REPS(i,s) FORS(i,0,s)

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 1;
struct P {
	int node, length;
};
vector<P> adj[MAX];
int dist[MAX];
bool visit[MAX];
int n;
int dfs(int pos) {
	visit[pos] = true;
	int ret = pos;	
	for(auto &p : adj[pos]) {
		if(!visit[p.node]) {
			dist[p.node] += dist[pos] + p.length;
			int next = dfs(p.node);
			if(dist[next] > dist[ret])
				ret = next;
		}
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int u, v, len;
		scanf("%d%d%d", &u, &v, &len);
		adj[u].push_back({v, len});
		adj[v].push_back({u, len});
	}
	int ans = dfs(1);
	memset(visit, false, sizeof(visit));
	memset(dist, 0, sizeof(dist));
	ans = dfs(ans);
	printf("%d\n", dist[ans]);
}

// ����
// ������ ���� Ʈ���� ������ ���̳ʸ� Ʈ����� ������ Ǯ� Ʋ�ȴ�.
// �ٽ� ������ϴٰ� ������ ������ ����� ������ ���̰� ��Ʈ�� �������� ���� �� �ִٴ�
// ������ ���� ��Ʈ���� ����� ��� X
// X��忡�� ���� �� ��� Y�� ���ϴ� ������� Ǯ����.

// ������ �ҽ��� ������߰ڴ�.
// ���ݻ��캸�� �� �����ϰԵ� Ǯ����.
// ��Ʈ�� ����� ����Ʈ������ �ִ���̸� ������ ���ѰͰ�,
// ����Ʈ�� �������� �ִ���̸� ���� ���� ���ϴ¹���̴�.


// #include <bits/stdc++.h>
// using namespace std;
// vector<vector<int> > adj, weight;
// vector<int> sum, sum2;
// int n, a, b, c, M;
// int post(int cur, int wei) {
// 	int ret = 0;
// 	if(adj[cur].empty()) return wei;
// 	REP(i, adj[cur].size()) {
// 		int t = ret;
// 		ret += post(adj[cur][i], weight[cur][i]);
// 		sum.push_back(ret);
// 		ret = max(t, ret - t);
// 	}
// 	return ret + wei;
// }
// int main() {
// 	scanf("%d", &n);
// 	adj.resize(n + 2);
// 	weight.resize(n + 2);
// 	REP(i, n - 1) {
// 		scanf("%d%d%d", &a, &b, &c);
// 		adj[a].push_back(b);
// 		weight[a].push_back(c);
// 	}
// 	REP(i, adj[1].size()) {
// 		sum2.push_back(post(adj[1][i], weight[1][i]));
// 	}
// 	sort(sum2.begin(), sum2.end());
// 	sort(sum.begin(), sum.end());
// 	if(sum2.size() > 1) {
// 		M = sum2[sum2.size() - 1] + sum2[sum2.size() - 2];
// 	} else {
// 		M = sum2.back();
// 	}
// 	if(!sum.empty()) 
// 		M = max(sum.back(), M);
// 	printf("%d\n", M);
// }