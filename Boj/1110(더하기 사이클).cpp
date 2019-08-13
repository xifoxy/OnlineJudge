#include <bits/stdc++.h>
int N;
int f(int n1, int n2) {
	if(!(n1+n2)) return 1;
	int cal = (n1 + n2) % 10;
	cal += (n2 * 10);
	if(cal != N) return f(cal / 10, cal % 10) + 1;
	return 1;
}

int main() {
	scanf("%d", &N);
	if(N < 10)
		printf("%d\n", f(0, N));
	else
		printf("%d\n", f(N / 10, N % 10));
	return 0;
}

// 설명
// 입력으로 들어온 숫자가 나올때까지 문제에서 주어진 방법대로 계속 돌리면 된다.