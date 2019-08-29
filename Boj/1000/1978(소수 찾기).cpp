#include <iostream>
using namespace std;
bool d[1001];
int n, ans;
int main() {
	d[0] = d[1] = true;
	for(int i = 2; i * i <= 1000; ++i) {
		if(!d[i]) for(int j = i * i; j <= 1000; j += i) {
			d[j] = true;
		}
	}
	cin >> n;
	for(int o, i = 0; i < n; ++i) {
		cin >> o;
		if(!d[o]) ans++;
	}
	cout << ans;
}

// Ό³Έν(Sieve of Eratosthenes)