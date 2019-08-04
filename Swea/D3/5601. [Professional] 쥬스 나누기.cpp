#include <bits/stdc++.h>
using namespace std;
int T, n;
int main() {
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		cin >> n;
		printf("#%d ", tc);
		for(int i = 0; i < n; ++i)
			printf("1/%d ", n);
		puts("");
	}
}

//이해불가 생략