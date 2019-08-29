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

// ����(DFS)
// �̰� ����� 7���̳� Ʋ�ȴ�..
// Ǫ�°� �������� �����ϴ�.
// ������带 ī���� �� �� �ִ� �Լ���, ��带 �����ϴ� �Լ� �ΰ��� �ȴ�.
// Input�� Ʈ���� ���·� ������ ������ ����� �������� Ǫ���� �ʿ䰡 ���� ������
// �׳� Ʈ�� ���·� �׷����� �𵨸� �ϸ� �ȴ�.

// �׸��� ������ ���� ���� Ž���ϸ鼭 ����Ʈ������ 
// Ư�� ��Ʈ ��忡�� �ڽĳ��� �߰��� �Ǹ� �װ͸� �����ϸ�ȴ�.
// �׷��� ������ ���� ����� ������ Ž���� �� ���� �����̴�.

// ex)
// root = 1, del = 2
// [1] = (2),3
// [2] = 4,5 (Ž���Ұ�)
// [3] = 6,7
// [4] = 9 (Ž���Ұ�)
// �̷��� Ʈ���� �ִٰ� �غ���.
// �Է°��� Ʈ���� �����̱� ������ �׷����� �ܹ����̶�
// ��Ʈ ��忡 �޷��ִ� 2���� �����Ѵٸ� 2�� ���� ����� �ڽĵ��� ����� Ž������ �ɸ����� ����.