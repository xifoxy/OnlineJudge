#include <bits/stdc++.h>
using namespace std;
int T;
int main() {
	string s;
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		cin >> s;

		bool ans = true;
		int l = 0, r = s.size() - 1;
		while(l <= r) {
			if(s[l++] != s[r--])
				ans = false;
		}
		cout << '#' << tc << ' ' << (ans ? 1 : 0) << '\n';
	}
}

//»ý·«