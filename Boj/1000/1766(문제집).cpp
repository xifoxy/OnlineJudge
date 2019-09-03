#include <bits/stdc++.h>
using namespace std;
const int M = 32e3 + 1;
int indegeree[M];
vector<int> adj[M];
int main(){
	int problem, query;
	scanf("%d%d", &problem, &query);

	for(int i = 0; i < query; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		indegeree[v]++;
	}

	priority_queue<int, vector<int>, greater<int>> PQ;
	for(int i = 1; i <= problem; ++i){
		if(!indegeree[i]) PQ.push(i);
	}

	for(int i = 1; i <= problem; ++i){
		int cur = PQ.top();
		PQ.pop();
		printf("%d ", cur);

		for(auto &next : adj[cur]){
			if(!--indegeree[next]) PQ.push(next);
		}
	}
}

// 설명(Topological Sort)
// 위상정렬을 이용하되 "쉬운문제 부터 푼다" 즉 번호가 낮은 순서대로 풀어야 하기 때문에
// 우선순위 큐를 이용해준다. 사이클이 존재하는 케이스가 주어지지 않기 때문에 바로바로 출력하면된다.