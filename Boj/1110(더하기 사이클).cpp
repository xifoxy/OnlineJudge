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
// 겹치는 부분이 최대한 많은 곳이 답이 된다.