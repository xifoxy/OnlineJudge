#include <bits/stdc++.h>
using namespace std;
int sum, a, b, ans;
int main() {
	for(int i = 0; i < 4; ++i) {
		cin >> a >> b;
		sum -= a;
		sum += b;
		ans = max(sum, ans);
	}
	cout << ans;
}

//»ı·«