#include <bits/stdc++.h>
using namespace std;
int n, a, b, ans;
int main() {
	scanf("%d %d %d", &n, &a, &b);
	if(a > b) swap(a, b);
	while(!(a % 2 && b - 1 == a)) {
		a = a % 2 ? a / 2 + 1 : a / 2;
		b = b % 2 ? b / 2 + 1 : b / 2;
		ans++;
	}
	printf("%d\n", ans + 1);
}

// 만나지 않을수가 없다.