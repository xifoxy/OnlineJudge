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

//설명
//문제를 잘 읽어보면 componet의 갯수를 세어야 하는 문제이다.
//단방향 그래프이고 연결요소는 각 1개 이기 때문에 2차원 배열이 필요없다.
//각 정점과 연결되는 정점을 저장해준 뒤 DFS or BFS연결요소를 순차 탐색 해주면된다.
//방문하지 않은 bool배열을 만나면 사이클의 갯수가 추가되는 거니 답을 1씩 추가해주면 된다.