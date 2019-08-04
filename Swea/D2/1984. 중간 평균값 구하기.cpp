#include <bits/stdc++.h>
using namespace std;
int d[10], T;
int main() {
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		int sum = 0;
		for(int i = 0; i < 10; ++i) {
			cin >> d[i];
			sum += d[i];
		}
		sort(d, d + 10);
		sum -= d[0];
		sum -= d[9];
		int avg = round((1.0 * sum / 8));
		printf("#%d %d\n", tc, avg);
	}
}

//»ý·«