#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> vec;
int n, m, u, v, ans;
bool visited[1001];
void get_component_cnt(int pos) {
	visited[pos] = true;
	for(auto p : vec[pos]) {
		if(!visited[p])
			get_component_cnt(p);
	}
}
int main() {
	cin >> n >> m;
	vec.resize(n + 1);
	for(int i = 0; i < m; ++i) {
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i) {
		if(!visited[i]) {
			ans++;
			get_component_cnt(i);
		}
	}
	cout << ans;
}

//����
//Component�� ������ ���ϴ� ����� visited �迭�� �̿��ϸ� �ȴ�,
//������ ���� N �̶�� 1~N���� �̱� ������ 1���� �湮���� ���� ������ �湮�ؼ�
//�湮���� ���� ������ �����ҵ��� ��ȸ�ϸ鼭 �湮�ϸ� �ȴ�.
//Ž���� �ʺ� Ȥ�� ���� ���� �ƹ��ų� �����ص� �������.
//�� ������ ª�� dfs�� �̿��ߴ�.
