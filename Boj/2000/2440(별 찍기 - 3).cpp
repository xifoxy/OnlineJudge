#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	cin >> n;
	for(int i = n; i > 0; --i) {
		for(int j = 0; j < i; ++j)
			cout << '*';
		cout << '\n';
	}
}

// 이런거 못풀면 자살해야된다.