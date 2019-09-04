#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 1;
struct node{
	int v, cost;
};
vector<node> adj[M];
bool visit[M];
int dp[M];
int n, ans;
void sol(int cur, int cost){
	visit[cur] = true;
	for(auto &next : adj[cur]){
		if(!visit[next.v]){
			dp[next.v] = max(dp[next.v], cost + next.cost);
			if(dp[ans] > dp[next.v]) ans = next.v;
			sol(next.v, dp[next.v]);
		}
	}
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int u, v, c;
		scanf("%d", &u);
		while(1){
			scanf("%d", &v);
			if(v == -1) break;
			scanf("%d", &c);
			adj[u].push_back({v, c});
		}
	}
	sol(1, 0);
	memset(visit, false, sizeof(visit));
	memset(dp, 0, sizeof(dp));
	sol(ans, 0);
	printf("%d\n", dp[ans]);
}

// ����(DFS)
// ���� ����ϰ� �Ҽ� �ִµ� �����Ƽ�(��� ���� �Ӹ� �ȵ��ư���) �� �帨�� �������.
// DFS�ѹ� �����鼭 ����� ���� �ΰ��� �߷��� �ΰ��� ���Ѱ��� ��ȯ���ָ� �ȴ�.
// ���� ������ ��Ʈ ���� ���� �հ��� ���ϰ�
// ���� �� ��带 �ٽ� ��Ʈ�� �ΰ� ���� �� �Ÿ����� ���� ����ؼ� �����ߴ�.