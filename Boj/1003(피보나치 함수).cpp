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

// DP�⺻�����̴�.
// N��° �Ǻ���ġ���� 0�� 1�� ȣ��Ǵ� Ƚ���� ����ϴ� �����ε� ���ذ� ���� �ʴ´ٸ�
// �׸��� �׷����°� ����.

// �Ʒ� ���� �ڼ��� ���캸�� �ߺ��Ǵ� �κ��� Memoizaition�ȴ�. 
// fib(2) = fib(1) + fib(0) 
// fib(3) = fib(2) + fib(1) == fib(2)������ ȣ��� ���� fib(1)������ ȣ��� ���� ���Ѵ�.
// fib(4) = fib(3) + fib(2) == fib(3) + fib(2) ���� ȣ��� ���� ���Ѵ�.