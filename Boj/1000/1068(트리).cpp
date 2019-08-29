#include <bits/stdc++.h>
using namespace std;
int n, parent, ans;
vector<int> adj[51];
bool visit[51];
int node_cnt(int x, int del_node) {
	visit[x] = true;
	if(adj[x].size() == 0) return 1;
	int ret = 0;
	for(auto &p : adj[x]) {
		if(!visit[p]) {
			ret += node_cnt(p, del_node);
		}
	}
	return ret;
}
void delete_node(int root , int del) {
	for(int i = 0; i < adj[root].size(); ++i) {
		if(adj[root][i] == del) {
			adj[root].erase(adj[root].begin() + i);
			return;
		}
		delete_node(adj[root][i], del);
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int node;
		scanf("%d", &node);
		if(node == -1)
			parent = i;
		else adj[node + 1].push_back(i);
	}
	int del_node;
	scanf("%d", &del_node);
	del_node++;
	if(parent == del_node) puts("0");
	else {
		delete_node(parent, del_node);
		printf("%d\n", node_cnt(parent, del_node));
	}
}

// 설명(DFS)
// 이게 뭐라고 7번이나 틀렸다..
// 푸는건 생각보다 간단하다.
// 리프노드를 카운팅 할 수 있는 함수와, 노드를 삭제하는 함수 두개면 된다.
// Input이 트리의 형태로 들어오기 때문에 양방향 간선으로 푸시할 필요가 없기 때문에
// 그냥 트리 형태로 그래프를 모델링 하면 된다.

// 그리고 삭제할 노드는 순차 탐색하면서 서브트리들의 
// 특정 루트 노드에서 자식노드로 발견이 되면 그것만 삭제하면된다.
// 그러면 삭제된 노드와 연결된 노드들은 탐색할 수 없기 때문이다.

// ex)
// root = 1, del = 2
// [1] = (2),3
// [2] = 4,5 (탐색불가)
// [3] = 6,7
// [4] = 9 (탐색불가)
// 이러한 트리가 있다고 해보자.
// 입력값이 트리의 형태이기 때문에 그래프는 단방향이라서
// 루트 노드에 달려있는 2번만 삭제한다면 2번 노드와 연결된 자식들은 절대로 탐색에서 걸릴수가 없다.