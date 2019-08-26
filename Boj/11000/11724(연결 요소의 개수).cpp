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

//설명
//Component의 갯수를 구하는 방법은 visited 배열을 이용하면 된다,
//정점의 수가 N 이라면 1~N까지 이기 때문에 1부터 방문하지 않은 정점을 방문해서
//방문하지 않은 정점의 연결요소들을 순회하면서 방문하면 된다.
//탐색은 너비 혹은 깊이 둘중 아무거나 선택해도 상관없다.
//난 구현이 짧아 dfs를 이용했다.
