#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
	for(int tc = 1; tc <= 10; ++tc) {
		cin >> n >> a >> b;
		int sum = 1;
		for(int i = 0; i < b; ++i)
			sum *= a;
		printf("#%d %d\n", tc, sum);
	}
}

//»ý·«