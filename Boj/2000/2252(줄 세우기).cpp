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

// ����(Topological Sort)
// �������� �⺻ �����̴�. ���������� ����ϰ� ���������� 0�� �Ǵ� ������� ����ϸ�ȴ�.
// ���� ���� �� ���� ���� �־����� �ʱ� ������ ���� ������ �ʿ� ���� �ٷιٷ� ����ϸ�ȴ�.