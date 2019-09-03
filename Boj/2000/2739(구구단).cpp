#include <cstdio>

void gugu(int n, int x) {
	if(x > 1) gugu(n, x - 1);
	printf("%d * %d = %d\n", n, x, n * x);
}

int main() {
	int n;
	scanf("%d", &n);
	gugu(n, 9);
	return 0;
}

// 말하지 않아도 알아요~