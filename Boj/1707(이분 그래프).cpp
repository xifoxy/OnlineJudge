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

//����
//�켱 �̺� �׷��� ���� ���� ���ڸ�, ���� ��ġ�� ������ �������̶��
//������ ��ҵ��� �Ķ����̾�ߵȴ�. ��ͷ� Ǯ���� �Ͽ����� ������ ���̰� ������� ������
//ť�� �̿��� �ʺ�Ž������ �����ߴ�.
//�ַ���� �ٽ� �κ��� �÷��� �������ִ� �κ��̴�.
//rb = rb == 1 ? 2 : 1
//rb = color[next] == 1 ? 2 : 1
//���� ó���־��� Ʋ�ȴ� �ҽ��̰� �ι�°�� �¾Ҵ�.
//���� ������ ������ 1�̸� 2�� �־
//������ ������ 2�� �ƴϸ� ������ ����ϸ� �ȴ�.