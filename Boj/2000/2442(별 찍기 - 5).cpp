#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n - 1; ++j)
			cout << ' ';
		for(int j = 0; j < i * 2 - 1; ++j)
			cout << '*';
		cout << '\n';
	}
}

// 이런거 못풀면 자살해야된다.