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

// 설명
// 예제만 보고 트리의 구조가 바이너리 트리라는 전제로 풀어서 틀렸다.
// 다시 고민좀하다가 문제를 접근한 방식은 지름의 길이가 루트를 포함하지 않을 수 있다는
// 예제를 보고 루트에서 가장먼 노드 X
// X노드에서 가장 먼 노드 Y를 구하는 방법으로 풀었다.

// 과거의 소스도 살펴봐야겠다.
// 지금살펴보니 참 난잡하게도 풀었다.
// 루트에 연결된 서브트리들의 최대길이를 일일이 구한것과,
// 서브트리 내에서의 최대길이를 구해 값을 비교하는방법이다.


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