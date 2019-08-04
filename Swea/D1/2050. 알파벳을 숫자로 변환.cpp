#include <bits/stdc++.h>
using namespace std;
int main() {
	string str;
	cin >> str;
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	for(int i = 0; i < str.length(); ++i) {
		cout << str[i] - 64 << ' ';
	}
}

//»ı·«