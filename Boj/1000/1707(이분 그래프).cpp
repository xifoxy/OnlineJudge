#include <bits/stdc++.h>
using namespace std;
int tc, n, m, u, v;
int color[20001];
bool bfs(int pos, vector<vector<int>> &v, int rb = 1) {
	// 시작노드는 무조건 1번색깔을 칠한다.
	color[pos] = rb;
	queue<int> Q; Q.push(pos);
	while(!Q.empty()) {
		int current = Q.front(); Q.pop();
		// current 노드의 색을 확인하고 반대되는 색을 기입한다.
		rb = color[current] == 1 ? 2 : 1;
		for(auto &next : v[current]) {
			// next노드가 처음 방문일경우 currnet와 반대되는 색상을 갱신
			if(!color[next]) {
				Q.push(next);
				color[next] = rb;
			} else if(color[next] != rb) return false;
			// next노드가 이미 방문했던 노드이면 색을 비교한다.
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
			// 노드의 방문여부를 확인하기 위해 color배열은 0으로 초기화된 배열을 쓴다.
			// 이렇게하면 컴포넌트가 여러개일 경우도 구별이 가능하다.
			if(!color[i] && ans)
				ans = bfs(i, vec);
		}
		if(ans) cout << "YES" << '\n';
		else cout << "NO" << '\n';
		memset(color, 0, sizeof(color));
	}
}

// 설명(Graph, BFS)
// 우선 이분 그래프에 대한 개념의 이해가 필요하다.
// 인접한 정점끼리 서로 다른 색을 칠해서 모든 정점을 두가지 색으로 칠할수 있으면 이분 그래프이다.
// 간선의 수도 상관없고 오로지 정점의 연결 관계도가 핵심인 문제이다.