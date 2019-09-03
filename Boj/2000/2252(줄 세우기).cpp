#include <bits/stdc++.h>
using namespace std;
const int M = 32e3 + 1;
int indegeree[M], result[M];
int n, m;
vector<int> adj[M];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		indegeree[v]++;
	}

	queue<int> Q;
	for(int i = 1; i <= n; ++i)
		if(!indegeree[i]) Q.push(i);

	for(int i = 1; i <= n; ++i){
		int cur = Q.front();
		Q.pop();

		printf("%d ", cur);
		for(auto &next : adj[cur]){
			if(!--indegeree[next])
				Q.push(next);
		}
	}
}

// 설명(Topological Sort)
// 위상정렬 기본 문제이다. 진입차수를 계산하고 진입차수가 0이 되는 순서대로 출력하면된다.
// 줄을 세울 수 없는 경우는 주어지지 않기 때문에 따로 저장할 필요 없이 바로바로 출력하면된다.