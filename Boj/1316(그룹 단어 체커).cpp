#include <bits/stdc++.h>
using namespace std;
int d[26], tc, ans;
int main() {
	cin >> tc;
	for(int t = 0; t < tc; ++t) {
		string str; cin >> str;
		memset(d, 0, sizeof(d));
		for(int i = 0; i < str.size(); ++i) {
			if(d[str[i] - 'a'] && str[i - 1] != str[i]) {
				ans++;
				break;
			} else d[str[i] - 'a']++;
		}
	}
	cout << tc - ans;
}

//»ý·«