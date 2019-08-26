#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 1;
int d[MAX], n;
int main() {
	d[0] = 1, d[1] = 3;
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i) {
		d[i] = (d[i - 1] * 2 + d[i - 2]) % 9901;
	}
	printf("%d\n", d[n]);
}

// 설명(DP)
// 점화식을 세울때 고려해야할 부분은 세가지 정도 되겠다.
// 사자를 왼쪽에만 배치하는 경우
// 사자를 오른쪽에만 배치하는 경우
// 둘다 없는 경우
// 이 세가지를 다 더한 경우가 N크기의 우리에 사자를 놓을수 있는 경우의 수가 된다.