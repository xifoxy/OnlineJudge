#include <bits/stdc++.h>
using namespace std;
int main() {
	int L, A, B, C, D;
	cin >> L >> A >> B >> C >> D;
	while((A > 0 || B > 0) && L--) {
		A -= C;
		B -= D;
	}
	cout << L;
}

// 생략