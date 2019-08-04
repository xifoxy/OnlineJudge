#include <iostream>
#include <cstring>
using namespace std;
int tc, m, n, k, x, y;
int farm[50][50];
bool visit[50][50];
bool safe(int x, int y) { return x >= 0 && y >= 0 && x < m && y < n; }
void dfs(int x, int y) {
	if(!safe(x, y)) return;
	if(visit[x][y] || !farm[x][y]) return;
	visit[x][y] = true;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
}
int main() {
	cin >> tc;
	while(tc--) {
		cin >> m >> n >> k;
		memset(farm, 0, sizeof(farm));
		memset(visit, false, sizeof(visit));
		for(int i = 0; i < k; ++i) {
			cin >> x >> y;
			farm[x][y] = 1;
		}
		int cnt = 0;
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				if(!visit[i][j] && farm[i][j])
					dfs(i, j), cnt++;
		cout << cnt << '\n';
	}
}

//연결된 컴포넌트의 개수를 세는 무제이다.
//조건은 4방검색이니 그냥 간단하게 풀린다.