#include <bits/stdc++.h>
#define M 1001
int d[M][M];
int R, C, Q;
int main() {
	scanf("%d%d%d", &Q, &R, &C);
	for(int i = 1; i <= Q; ++i) {
		for(int j = 1; j <= R; ++j) {
			scanf("%d", &d[i][j]);
			d[i][j] += d[i][j - 1] + d[i - 1][j] - d[i - 1][j - 1];
		}
	}
	for(int i = 0; i < C; ++i) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int divide = (x2 - x1 + 1) * (y2 - y1 + 1);
		int ans = d[x2][y2] - d[x1 - 1][y2] - d[x2][y1 - 1] + d[x1 - 1][y1 - 1];
		ans /= divide;
		printf("%d\n", ans);
	}
}

//설명(Prefix Sum)
//구간합 배열을 통해서 답을 만들수 있다.
// 1 <= R, C <= 1e3 그리고 1 <= C <= 1e5 이기 때문에 완전탐색시 입력 제외하고
//O(N^2*M) 대략 10억 나오기 때문에 2차원 구간합 배열이 필요하다.