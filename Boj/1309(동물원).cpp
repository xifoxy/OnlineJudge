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

//간단한 DP문제
//수식을 세워보면된다.