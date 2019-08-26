#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
	cin >> a >> b >> c;
	a = min(a, min(b, c));
	cin >> b >> c;
	b = min(b, c);
	cout << a + b - 50;
}

//이런거 못풀면 자살해야된다.