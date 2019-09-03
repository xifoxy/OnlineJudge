#include <iostream>
using namespace std;
long long d[91];
int main() {
	d[1] = 1;
	int n;
	cin >> n;
	for(int i = 2; i <= n; ++i) {
		d[i] = d[i - 1] + d[i - 2];
	}
	cout << d[n];
}

// 말하지 않아도 알아요~