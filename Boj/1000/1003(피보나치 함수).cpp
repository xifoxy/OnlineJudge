#include <bits/stdc++.h>
using namespace std;
int z[41], o[41];
int tc, a;
int main() {
	z[0] = o[1] = 1;
	scanf("%d", &tc);
	for(int i = 2; i <= 40; ++i) {
		z[i] = z[i - 1] + z[i - 2];
		o[i] = o[i - 1] + o[i - 2];
	}
	while(tc--) {
		scanf("%d", &a);
		printf("%d %d\n", z[a], o[a]);
	}
}

// DP기본문제이다.
// N번째 피보나치에서 0과 1이 호출되는 횟수를 출력하는 문제인데 이해가 가지 않는다면
// 그림을 그려보는게 좋다.

// 아래 식을 자세히 살펴보면 중복되는 부분이 Memoizaition된다. 
// fib(2) = fib(1) + fib(0) 
// fib(3) = fib(2) + fib(1) == fib(2)에서의 호출된 값과 fib(1)에서의 호출된 값을 더한다.
// fib(4) = fib(3) + fib(2) == fib(3) + fib(2) 에서 호출된 값을 더한다.