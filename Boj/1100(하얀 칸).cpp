#include <bits/stdc++.h>
using namespace std;
string s[8];
int ans;
int main() {
	for(int i = 0; i < 8; ++i)
		cin >> s[i];
	for(int i = 0; i < 8; ++i) {
		for(int j = 0; j < 8; ++j) {
			if(i % 2 == 0 && j % 2 == 0 && s[i][j] != '.')
				ans++;
			if(i % 2 && j % 2 && s[i][j] != '.') ans++;
		}
	}
	cout << ans;
}

// ³ë°¡´Ù