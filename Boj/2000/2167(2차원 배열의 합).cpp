#include <bits/stdc++.h>
using namespace std;
int pSum[301][301], n, m, val;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		cin >> val;
		pSum[i][j] = pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1] + val;
	}
	int tc;
	cin >> tc;
	while(tc--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << pSum[x2][y2] - pSum[x2][y1 - 1] - pSum[x1 - 1][y2] + pSum[x1 - 1][y1 - 1] << '\n';
	}
}

// 설명(2D Prefix Sum)
// 이차원 배열의 구간합 기본 문제
// 개념 숙지부터 하자.