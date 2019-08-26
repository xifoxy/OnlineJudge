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

//1이 속한 컴포넌트의 노드 갯수를 검색하는 문제이다.
//방문자 배열을 통해서 1과 연결된 노드를 카운팅해주면된다.