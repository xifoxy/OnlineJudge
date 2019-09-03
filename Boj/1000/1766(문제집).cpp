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

// ����(Topological Sort)
// ���������� �̿��ϵ� "����� ���� Ǭ��" �� ��ȣ�� ���� ������� Ǯ��� �ϱ� ������
// �켱���� ť�� �̿����ش�. ����Ŭ�� �����ϴ� ���̽��� �־����� �ʱ� ������ �ٷιٷ� ����ϸ�ȴ�.