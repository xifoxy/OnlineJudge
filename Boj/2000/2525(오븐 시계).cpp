#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
	cin >> a >> b >> c;
	b += c;
	a += (b / 60); b %= 60;
	a %= 24;
	cout << a << ' ' << b;
}

//이런거 못풀면 자살해야된다.