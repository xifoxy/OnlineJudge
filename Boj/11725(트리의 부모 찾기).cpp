#include <bits/stdc++.h>
using namespace std;
int parent[100001];
vector<vector<int>> vec;
int n, u, v;
void dfs(int pos) {
	for(auto &p : vec[pos]) {
		if(!parent[p]) {
			parent[p] = pos;
			dfs(p);
		}
	}
}
int main() {
	scanf("%d", &n);
	vec.resize(n + 1);
	for(int i = 0; i < n - 1; ++i) {
		scanf("%d%d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1);
	for(int i = 2; i <= n; ++i) {
		printf("%d\n", parent[i]);
	}
}

//����
//������ ���� 1�� ������ ���ذ� �Ȱ� �� ������, �������� ģ���� ��Ʈ�� 1�̶�� ��������.
//�ܹ����� ������ �����Ϸ��� ��������� �Է��ؼ� ��Ʈ���� Ž���ؾߵȴ�.
//������ �Է��� a,b�� �ִٰ� ġ�� ����� �θ����� ������ �־����� �ʱ� �����̴�.