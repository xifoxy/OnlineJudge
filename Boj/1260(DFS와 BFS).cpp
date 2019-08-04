#include <bits/stdc++.h>
using namespace std;
int n, k, st, u, v;
bool visited[1001];

void dfs(int pos, vector<vector<int>> &v) {
	visited[pos] = true;
	cout << pos << ' ';
	for(auto &p : v[pos]) {
		if(!visited[p])
			dfs(p, v);
	}
}
void bfs(int pos, vector<vector<int>> &v) {
	queue<int> Q; Q.push(pos);
	cout << pos << ' ';
	visited[pos] = true;
	while(!Q.empty()) {
		int next = Q.front(); Q.pop();
		for(auto &p : v[next]) {
			if(!visited[p]) {
				Q.push(p);
				visited[p] = true;
				cout << p << ' ';
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k >> st;
	vector<vector<int>> vec(n + 1);
	for(int i = 0; i < k; ++i) {
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for(int i = 0; i < n; ++i)
		sort(vec[i].begin(), vec[i].end());
	dfs(st, vec); cout << '\n';
	memset(visited, false, sizeof(visited));
	bfs(st, vec);
}

//»ý·«