#include <bits/stdc++.h>
using namespace std;
int tc, n, d[1001];
bool visited[1001];
void dfs(int pos) {
	visited[pos] = true;
	int next = d[pos];
	if(!visited[next])
		dfs(next);
}
int main() {
	cin >> tc;
	while(tc--) {
		cin >> n;
		int ans = 0;
		for(int i = 1; i <= n; ++i)
			cin >> d[i];

		for(int i = 1; i <= n; ++i) if(!visited[i]) {
			dfs(i);
			ans++;
		}
		cout << ans << '\n';
		memset(visited, false, sizeof(visited));
	}
}

//����
//������ �� �о�� componet�� ������ ����� �ϴ� �����̴�.
//�ܹ��� �׷����̰� �����Ҵ� �� 1�� �̱� ������ 2���� �迭�� �ʿ����.
//�� ������ ����Ǵ� ������ �������� �� DFS or BFS�����Ҹ� ���� Ž�� ���ָ�ȴ�.
//�湮���� ���� bool�迭�� ������ ����Ŭ�� ������ �߰��Ǵ� �Ŵ� ���� 1�� �߰����ָ� �ȴ�.