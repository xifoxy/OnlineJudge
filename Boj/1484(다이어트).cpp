#include <bits/stdc++.h>
int n;
bool cmp;
int main() {
	scanf("%d", &n);
	long long l = 1, r = 1;
	while(r <= 50001) {
		if(r * r - l * l == n) {
			printf("%lld\n", r);
			cmp = true;
		}
		if(r * r - l * l >= n) ++l;
		else ++r;
	}
	if(!cmp) puts("-1");
}

// 설명
// 문제에 답이 나와있다.
// 현재 몸무게 Cur, 이전 몸무게 Bef
// Cur*Cur - Bef*Bef == n 이 될때마다 출력하면된다.