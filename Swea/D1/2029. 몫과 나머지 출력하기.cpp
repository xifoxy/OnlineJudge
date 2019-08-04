#include <bits/stdc++.h>
using namespace std;
int t, a, b, i;
int main() {
	scanf("%d", &t);
	for(; i < t; ++i) {
		scanf("%d%d", &a, &b);
		printf("#%d %d %d\n", i + 1, a / b, a % b);
	}
}

//»ý·«