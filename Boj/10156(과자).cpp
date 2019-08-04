#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
	cin >> a >> b >> c;
	a *= b;
	if(a > c) cout << a - c;
	else cout << 0;
}

//못풀면 자살하자.