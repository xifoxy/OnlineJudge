#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int gap = 1; gap <= n - i; ++gap)
			printf(" ");
		for(int star = 0; star < i; ++star)
			printf("*");
		puts("");
	}
	for(int i = 1; i < n; ++i) {
		for(int gap = 0; gap < i; ++gap)
			printf(" ");
		for(int star = 0; star < n - i; ++star)
			printf("*");
		puts("");
	}
}

// 이런거 못풀면 자살해야된다.