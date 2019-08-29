#include <bits/stdc++.h>
using namespace std;
int d[10];
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	string s = to_string(a*b*c);
	for(int i = 0; i < s.size(); ++i)
		d[s[i] - '0']++;

	for(int i = 0; i <= 9; ++i)
		cout << d[i] << '\n';
}

// ÀÚ»ì