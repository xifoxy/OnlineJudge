#include <bits/stdc++.h>
using namespace std;
int tc, n, m, u, v;
int color[20001];
bool bfs(int pos, vector<vector<int>> &v, int rb = 1) {
	color[pos] = rb;
	queue<int> Q; Q.push(pos);
	while(!Q.empty()) {
		int next = Q.front(); Q.pop();
		rb = color[next] == 1 ? 2 : 1;
		for(auto &p : v[next]) {
			if(!color[p]) {
				Q.push(p);
				color[p] = rb;
			} else if(color[p] != rb) return false;
		}
	}
	return true;
}
int main() {
	cin >> tc;
	while(tc--) {
		cin >> n >> m;
		vector<vector<int>> vec(n + 1);
		for(int i = 0; i < m; ++i) {
			cin >> u >> v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		bool ans = true;
		for(int i = 1; i <= n; ++i) {
			if(!color[i] && ans)
				ans = bfs(i, vec);
		}
		if(ans) cout << "YES" << '\n';
		else cout << "NO" << '\n';
		memset(color, 0, sizeof(color));
	}
}

//설명
//우선 이분 그래프 부터 정의 하자면, 현재 위치의 정점이 빨간색이라면
//인접한 요소들은 파란색이어야된다. 재귀로 풀려고 하였으나 스택의 깊이가 깊어지기 때문에
//큐를 이용한 너비탐색으로 진행했다.
//솔루션의 핵심 부분은 컬러를 지정해주는 부분이다.
//rb = rb == 1 ? 2 : 1
//rb = color[next] == 1 ? 2 : 1
//위는 처음넣었서 틀렸던 소스이고 두번째는 맞았다.
//현재 정점의 색깔이 1이면 2를 넣어서
//인접한 정점이 2가 아니면 오답을 출력하면 된다.