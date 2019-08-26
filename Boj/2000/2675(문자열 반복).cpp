#include <bits/stdc++.h>
using namespace std;
int tc, n;
string s;
int main() {
	cin >> tc;
	while(tc--) {
		cin >> n >> s;
		for(int i = 0; i < s.size(); ++i)
			for(int j = 0; j < n; ++j)
				cout << s[i];
		cout << '\n';
	}
}

//»ý·«