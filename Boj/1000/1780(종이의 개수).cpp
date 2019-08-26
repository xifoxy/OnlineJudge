#include <bits/stdc++.h>
using namespace std;
const int MX = 2200;
int a[MX][MX], n;
int ans[3];
bool check(int x, int y, int s) {
	int cmp = a[x][y];
	for(int i = x; i < x + s; ++i)
		for(int j = y; j < y + s; ++j)
			if(cmp != a[i][j])
				return false;
	return true;
}

void sol(int x, int y, int s) {
	if(check(x, y, s)) {
		ans[a[x][y] + 1]++;
		return;
	}
	int m = s / 3;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			sol(x + i * m, y + j * m, m);
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	sol(0, 0, n);
	printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);
}

// 설명
// 분할정복은 언제나 적응이 안되는 문제이다.
// 문제의 크기는 3^N으로 주어지고 예제를 잘 살펴보면
// 3*3안에 숫자가 하나로 통일되지 않으면 전부다 낮장으로 구분한다.
// N의 크기가 3의 제곱수 이기 때문에 3이라는 숫자를 잘 가지고 놀면 쉽게 분할이 된다.