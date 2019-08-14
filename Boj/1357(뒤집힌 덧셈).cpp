#include <bits/stdc++.h>
using namespace std;
int a, b;
int f(int n) {
	int ret = 0;
	while(n) {
		ret *= 10;
		ret += n % 10;
		n /= 10;
	}
	return ret;
}
int main() {
	scanf("%d%d", &a, &b);
	printf("%d\n", f(f(a) + f(b)));
}

// 설명
// 두 숫자를 뒤집어서 더해준걸 다시 뒤집어서 출력하자.