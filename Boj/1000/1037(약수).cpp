#include <bits/stdc++.h>
using namespace std;
int n, mx, mn = 1e8, a;
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		mx = max(a, mx);
		mn = min(a, mn);
	}
	cout << mx * mn;
}

// »ý·«