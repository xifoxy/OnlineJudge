#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
	for(int i = 0; i < 3; ++i) {
		cin >> a >> b;
		c ^= a;
		d ^= b;
	}
	printf("%d %d", c, d);
}

// 쉬어가는 문제