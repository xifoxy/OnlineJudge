#include <bits/stdc++.h>
using namespace std;
const int MX = 21;
char a[MX][MX];
int n, m, ans, dx[]{1,-1,0,0}, dy[]{0,0,1,-1};
bool visited[27];
bool safe(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}
void sol(int x, int y, int move_cnt) {
	ans = max(move_cnt, ans);
	for(int i = 0; i < 4; ++i) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if(safe(nx, ny) && !visited[a[nx][ny] - 'A']) {
			visited[a[nx][ny] - 'A'] = true;
			sol(nx, ny, move_cnt + 1);
			visited[a[nx][ny] - 'A'] = false;
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%s", a[i]);

	visited[a[0][0] - 'A'] = true;
	sol(0, 0, 1);
	printf("%d\n", ans);
}

// 설명(Brute Force, Next_Permutation)
// 한번 밟은 알파벳을 다시 밟을 수 없다. 순열을 구하는 방법과 유사하다.