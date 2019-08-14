#include <bits/stdc++.h>
using namespace std;
int n, q, d[1'000'1], a;
int main() {
	cin >> n >> q;
	for(int i = 0, idx = 0; i < n; ++i) {
		cin >> a;
		for(int j = 0; j < a; ++j) {
			d[idx++] = i + 1;
		}
	}
	for(int i = 0; i < q; ++i) {
		cin >> a;
		cout << d[a] << '\n';
	}
}

// 쉬어가는 문제