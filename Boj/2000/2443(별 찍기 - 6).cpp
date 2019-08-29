#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < i; ++j)
			cout << ' ';
		for(int j = 0; j < n * 2 - i * 2 - 1; ++j)
			cout << '*';
		cout << '\n';
	}
}

// 이런거 못풀면 자살해야된다.