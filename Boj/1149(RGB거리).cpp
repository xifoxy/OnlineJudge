#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 1;
int n;
int d[3][MAX];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d%d", &d[0][i], &d[1][i], &d[2][i]);

	for(int i = 1; i <= n; ++i) {
        // 현재 빨간색이면 녹색이나 파란색중 최솟값을
		d[0][i] += min(d[1][i - 1], d[2][i - 1]);
        // 현재 녹색이면 빨간색이나 파란색중 최솟값을
		d[1][i] += min(d[0][i - 1], d[2][i - 1]);
        // 현재 파란색이면 빨간색이나 녹색중 최솟값을
		d[2][i] += min(d[0][i - 1], d[1][i - 1]);
	}
	printf("%d\n", min(d[0][n], min(d[1][n], d[2][n])));
}

// 설명
// 같은 색이 연속되지 않게 퐁당퐁당만 잘해주면 된다.