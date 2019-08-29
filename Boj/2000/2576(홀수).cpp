#include <bits/stdc++.h>
using namespace std;
int sum, a, mn = 123;
int main() {
	for(int i = 0; i < 7; ++i) {
		cin >> a;
		if(a % 2) {
			sum += a;
			mn = min(a, mn);
		}
	}
	if(!sum) cout << -1;
	else cout << sum << '\n' << mn;
}

// 이런거 자살..