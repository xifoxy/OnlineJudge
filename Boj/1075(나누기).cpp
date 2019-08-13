#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	n = n / 100 * 100;
	if(n % m) {
		m = m - n % m;
		if(m < 10) printf("0%d\n", m);
		else printf("%d\n", m);
	} else puts("00");
}

// 설명(Math)
// 주어진 숫자는 100 <= N <= 2e9이고 나눌 숫자는 1 <= F <= 100 이다
// 무슨 말 인가 하면, 숫자가 얼마가 됐든 제일 뒤 숫자 두자리를 최솟값으로 만들어
// 나누어 떨어지게만 만들면 된다는 말이다.