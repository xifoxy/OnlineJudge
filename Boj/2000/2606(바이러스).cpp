#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> vec;
int n, m, u, v;
bool visited[101];
int df(int pos) {
	int ret = 0;
	visited[pos] = true;
	for(auto &p : vec[pos]) {
		if(!visited[p]) {
			ret += df(p) + 1;
		}
	}
	return ret;
}
int main() {
	cin >> n >> m;
	vec.resize(n + 1);
	for(int i = 0; i < m; ++i) {
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	cout << df(1);
}


// 설명(DFS)
// 1이 포함된 컴포넌트의 노드 갯수를 구하면 된다.