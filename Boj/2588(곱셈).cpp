#include <bits/stdc++.h>
using namespace std;
int a, b, ans;
int main() {
	cin >> a >> b;
	ans = a * b;
	while(b > 0) {
		cout << a * (b % 10) << '\n';
		b /= 10;
	}
	cout << ans;
}

//이런거 못풀면 자살해야된다.