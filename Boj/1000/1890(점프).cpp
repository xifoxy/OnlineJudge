#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100][100], n;
ll dp[100][100];
ll sol(int x, int y) {
	if(x >= n || y >= n) return 0;
	if(x == n - 1 && y == n - 1) return 1;
	ll &ret = dp[x][y];
	if(ret != -1) return ret;
	ret = 0;
	int jp = a[x][y];
	ret += sol(x + jp, y) + sol(x, y + jp);
	return ret;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			cin >> a[i][j];
	}
	memset(dp, -1, sizeof(dp));
	cout << sol(0, 0) << '\n';
}

// 설명
// 이 코드의 핵심은 방문한 곳을 0으로 초기화 한다는 것이다.
// 일종의 방문자 역할을 하는셈이다.
// 가능한지 불가능한지 스택을 쌓아가는 방법은
// 함수를 호출할때 해당 좌표에 값을 더하도록 유도하면 된다.
// 기저 단위로 범위를 벗어났을 경우는 0을 반환하고,
// D[N - 1][N - 1] 에 도착했을때는 1을 반환해서 값을 더해간다.
// 그럼 D[0][0]에는 방문할 수 있는 값이 쌓이도록 되어 있다.