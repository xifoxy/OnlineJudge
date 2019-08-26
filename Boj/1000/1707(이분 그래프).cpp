#include <bits/stdc++.h>
using namespace std;
int tc, n, m, u, v;
int color[20001];
bool bfs(int pos, vector<vector<int>> &v, int rb = 1) {
	// ���۳��� ������ 1�������� ĥ�Ѵ�.
	color[pos] = rb;
	queue<int> Q; Q.push(pos);
	while(!Q.empty()) {
		int current = Q.front(); Q.pop();
		// current ����� ���� Ȯ���ϰ� �ݴ�Ǵ� ���� �����Ѵ�.
		rb = color[current] == 1 ? 2 : 1;
		for(auto &next : v[current]) {
			// next��尡 ó�� �湮�ϰ�� currnet�� �ݴ�Ǵ� ������ ����
			if(!color[next]) {
				Q.push(next);
				color[next] = rb;
			} else if(color[next] != rb) return false;
			// next��尡 �̹� �湮�ߴ� ����̸� ���� ���Ѵ�.
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
			// ����� �湮���θ� Ȯ���ϱ� ���� color�迭�� 0���� �ʱ�ȭ�� �迭�� ����.
			// �̷����ϸ� ������Ʈ�� �������� ��쵵 ������ �����ϴ�.
			if(!color[i] && ans)
				ans = bfs(i, vec);
		}
		if(ans) cout << "YES" << '\n';
		else cout << "NO" << '\n';
		memset(color, 0, sizeof(color));
	}
}

// ����(Graph, BFS)
// �켱 �̺� �׷����� ���� ������ ���ذ� �ʿ��ϴ�.
// ������ �������� ���� �ٸ� ���� ĥ�ؼ� ��� ������ �ΰ��� ������ ĥ�Ҽ� ������ �̺� �׷����̴�.
// ������ ���� ������� ������ ������ ���� ���赵�� �ٽ��� �����̴�.