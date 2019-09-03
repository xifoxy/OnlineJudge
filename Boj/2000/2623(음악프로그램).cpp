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
		// ����Ŭ�� �����Ѵٸ� ������ ���� �ʾ� ť�� ��Եȴ�.
		if(Q.empty()){
			fail = true;
			break;
		}

		int cur = Q.front();
		Q.pop();
		// ���� ������ �� ��
		result[i] = cur;
		for(int next : adj[cur])
			if(!--indegree[next])
				Q.push(next);
	}

	// ����Ŭ�� �����Ѵٸ� 0�� ���
	if(!fail) for(int i = 1; i <= n; ++i)
		printf("%d\n", result[i]);
	else puts("0");
}

// ����(Topological Sort)
// ��帶�� ���������� ������ְ�, ��带 �����ϸ鼭 ���������� 0�� �Ǵ� ������� ��ŷ�� �Ű��ָ�ȴ�.