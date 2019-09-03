#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 2;
int indegree[M], result[M];
int n, m;
vector<int> adj[M];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i){
		int k, prev, cur;
		scanf("%d", &k);
		
		for(int i = 0; i < k; ++i){
			scanf("%d", &cur);
			if(i){
				indegree[cur]++;
				adj[prev].push_back(cur);
			}
			prev = cur;
		}
	}

	queue<int> Q;
	for(int i = 1; i <= n; ++i){
		if(!indegree[i]) Q.push(i);
	}

	bool fail = false;
	for(int i = 1; i <= n; ++i){
		// 사이클이 존재한다면 차수가 맞지 않아 큐가 비게된다.
		if(Q.empty()){
			fail = true;
			break;
		}

		int cur = Q.front();
		Q.pop();
		// 현재 순서에 들어갈 곡
		result[i] = cur;
		for(int next : adj[cur])
			if(!--indegree[next])
				Q.push(next);
	}

	// 사이클이 존재한다면 0을 출력
	if(!fail) for(int i = 1; i <= n; ++i)
		printf("%d\n", result[i]);
	else puts("0");
}

// 설명(Topological Sort)
// 노드마다 진입차수를 계산해주고, 노드를 삭제하면서 진입차수가 0이 되는 순서대로 랭킹을 매겨주면된다.