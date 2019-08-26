#include <bits/stdc++.h>
using namespace std;
const int MX = 100001;
int a[MX], n, m;
int main() {
	scanf("%d%d", &n, &m);
	queue<int> Q;
	for(int i = 0; i < 100001; ++i) a[i] = MX;
	a[n] = 1, Q.push(n);

	if(n > m) printf("%d\n", n - m);
	else {
		while(!Q.empty()) {
			int pos = Q.front(); Q.pop();
			if(pos * 2 <= MX && a[pos * 2] > a[pos] + 1) {
				a[pos * 2] = a[pos] + 1;
				Q.push(pos * 2);
			}
			if(pos - 1 >= 0 && a[pos - 1] > a[pos] + 1) {
				a[pos - 1] = a[pos] + 1;
				Q.push(pos - 1);
			}
			if(pos + 1 <= MX && a[pos + 1] > a[pos] + 1) {
				a[pos + 1] = a[pos] + 1;
				Q.push(pos + 1);
			}
		}
		printf("%d\n", a[m] - 1);
	}
}

// 설명(BFS, DP)
// 주어진 문제 규칙대로 메모이제이션 하면 된다.
// DP배열을 충분히 큰 숫자로 초기화 한 다음
// 현재 좌표 x->y 로 가는 최솟값을 갱신한다.