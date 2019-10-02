#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 1;
int d[M], n, Q;
int main() {
	scanf("%d%d", &n, &Q);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &d[i]);
		d[i] += d[i - 1];
	}
	while(Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", d[r] - d[l - 1]);
	}
}

// 설명(Prefix Sum)
// 값의 변경이 없기 때문에 입력받을때 값을 누적시켜 가면 된다.