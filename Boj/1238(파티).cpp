#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1e3 + 1, INF = 1e8;
struct P {
	int vertex, cost;
};
struct cmp {
	bool operator()(const P &a, const P &b) {
		return a.cost > b.cost;
	}
};

vector<P> adj[MAX_V];

int dijk(int start, int end) {
	priority_queue<P, vector<P>, cmp> PQ;
	bool visit[MAX_V]{0,};
	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);

	PQ.push({start, 0});
	dist[start] = 0;

	while(!PQ.empty()) {
		int cur;
		do {
			cur = PQ.top().vertex;
			PQ.pop();
		} while(!PQ.empty() && visit[cur]);
		if(visit[cur] || visit[end]) break;
		visit[cur] = true;

		for(auto &p : adj[cur]) {
			int next = p.vertex;
			int cost = p.cost;

			if(dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				PQ.push({next, dist[next]});
			}
		}
	}
	return dist[end];
}
int main() {
	int n, m, end;
	scanf("%d%d%d", &n, &m, &end);
	for(int i = 0; i < m; ++i) {
		int u, v, cost;
		scanf("%d%d%d", &u, &v, &cost);
		adj[u].push_back({v,cost});
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(i == end) continue;
		ans = max(ans, dijk(i, end) + dijk(end, i));
	}
	printf("%d\n", ans);
}

//#���ͽ�Ʈ��(Dijkstra's)

//1~N�� �������� ��Ƽ�� ������ X�� ������ ������ �ִܰŸ���
//X�� ������ ���� 1~N������ �ִܰŸ��� �� ���Ѵ�.
//�ΰ��� ���� �ִ밡 �Ǵ°��� ��ȯ�ϸ� �ȴ�.

//dijk�Լ��� ���� ���ǿ� 
//if(visit[cur] || visit[end]) break;
//���⼭ end������ �߰��ϸ� 68ms�� ������ �߰� ���� ������ 176ms�� ���´�.