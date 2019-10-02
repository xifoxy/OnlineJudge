#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, k;
		scanf("%d%d", &n, &k);
		vector<int> v(n), degree(n), result(n);
		vector<vector<int>> adj(n);

		for(int i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}

		for(int i = 0; i < k; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u - 1].push_back(v - 1);
			degree[v - 1]++;
		}

		queue<int> Q;
		for(int i = 0; i < n; ++i) {
			if(degree[i] == 0) {
				Q.push(i);
				result[i] = v[i];
			}
		}

		while(!Q.empty()) {
			int cur = Q.front();
			Q.pop();

			for(auto &next : adj[cur]) {
				result[next] = max(result[next], result[cur] + v[next]);
				if(--degree[next] == 0)
					Q.push(next);
			}
		}

		int ans;
		scanf("%d", &ans);
		printf("%d\n", result[ans - 1]);
	}
}

// ����(Topological Sort)
// �������� �⺻ �����̴�. ������ �ϰ� ������.. �⺻ ������ �����Ұ� ����.