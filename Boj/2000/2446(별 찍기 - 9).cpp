#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	for(int i = n - 1; i >= 0; --i) {
		for(int j = 0; j < n - i - 1; ++j)
			printf(" ");
		for(int j = 0; j < i * 2 + 1; ++j)
			printf("*");
		puts("");
	}

	for(int i = 1; i <= n - 1; ++i) {
		for(int j = i; j < n - 1; ++j)
			printf(" ");
		for(int j = 0; j < i * 2 + 1; ++j)
			printf("*");
		puts("");
	}
}

// 이런거 못풀면 자살해야된다.