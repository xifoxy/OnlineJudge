#include <iostream>
using namespace std;
int n, ans = 1;
int main() {
	cin >> n;
	if(!n) cout << 1 << '\n';
	else {
		for(int i = 1; i <= n; ++i)
			ans *= i;
		cout << ans << '\n';
	}
}

//»ý·«