#include <bits/stdc++.h>
using namespace std;
int a, b, n, g;
int gcd(int a, int b) {
	if(a % b == 0) return b;
	return gcd(b, a % b);
}
int main() {
	cin >> n;
	while(n--) {
		cin >> a >> b;
		g = a > b ? gcd(a, b) : gcd(b, a);
		cout << a * b / g << '\n';
	}
}

//»ý·«