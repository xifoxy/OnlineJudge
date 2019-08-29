#include <bits/stdc++.h>
using namespace std;
int s, a;
int main() {
	for(int i = 0; i < 5; ++i) {
		cin >> a;
		s += (a*a);
	}
	cout << s % 10 << '\n';
}

// 이런거 못풀면 자살해야된다.