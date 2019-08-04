#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int main() {
	scanf("%d", &n);
	while(n != 1) {
		n = n % 2 == 0 ? n / 2 : n * 3 + 1;
		cnt++;
	}
	printf("%d\n", cnt + 1);
}

// 생략