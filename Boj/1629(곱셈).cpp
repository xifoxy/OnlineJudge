#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int ret(int a, int b) {
	if(b == 0) return 1;
	int t = ret(a, b / 2);
	int r = 1LL * t * t % c;
	if(b % 2) r = 1LL * r * a % c;
	return r;
}
int main() {
	cin >> a >> b >> c;
	cout << ret(a, b) << '\n';
}

//