#include <bits/stdc++.h>
using namespace std;
const int M = 5e2+1;
int indegree[M], cost[M], result[M];
vector<int> adj[M];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &cost[i]);
		int v;
		while(scanf("%d", &v)){
			if(v == -1) break;
			adj[v].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> Q;
	for(int i = 1; i <= n; ++i){
		if(indegree[i] == 0){
			Q.push(i);
			result[i] = cost[i];
		}
	}

	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();

		for(auto &next : adj[cur]){
			result[next] = max(result[next], result[cur] + cost[next]);
			if(--indegree[next] == 0)
				Q.push(next);
		}
	}

	for(int i = 1; i <= n; ++i)
		printf("%d\n", result[i]);
}

// 설명(Topological Sort)
// 위상정렬 기본 문제이다. 설명을 하고 싶은데.. 기본 문제라 설명할게 없다.