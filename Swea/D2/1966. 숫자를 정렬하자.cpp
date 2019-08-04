#include <bits/stdc++.h>
using namespace std;
int tc, n;
int d[51];
int main() {
	cin >> tc;
	for(int i = 1; i <= tc; ++i) {
		cin >> n;
		for(int j = 0; j < n; ++j)
			cin >> d[j];
		sort(d, d + n);
		printf("#%d ", i);
		for(int j = 0; j < n; ++j)
			printf("%d ", d[j]);
		puts("");
	}
}

//»ý·«