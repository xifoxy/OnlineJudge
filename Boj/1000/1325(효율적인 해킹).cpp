#include <bits/stdc++.h>
using namespace std;
const int M = 1e4 + 1;
vector<int> adj[M];
bool visit[M];
int dp[M];
int n, m;

int sol(int cur){
	int ret = 0;
	visit[cur] = true;
	for(auto &next : adj[cur]){
		if(!visit[next]){
			ret += sol(next) + 1;
		}
	}
	return ret;
}

int main(){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &v, &u);
		adj[u].push_back(v);
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i){
		memset(visit, false, sizeof(visit));
		dp[i] = sol(i);
		ans = max(dp[i], ans);
	}

	for(int i = 1; i <= n; ++i){
		if(ans == dp[i])
			printf("%d ", i);
	}
}

// ����(Brute Force, DFS)
// ���� ���̺��ϰ� Ǯ����. �ϴ� �־��� �ð��� 5�ʶ� �ذ��� ������ SCC�� Ǯ��
// �� �ַ�Ǻ��� �ð��� �뷫 1/6���� �پ��� �ȴ�.
// SCC�н��ϰ� �ҽ��߰� �ؾ߰ڴ�.