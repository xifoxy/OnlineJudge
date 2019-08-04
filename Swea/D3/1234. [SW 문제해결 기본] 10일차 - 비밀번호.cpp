#include <bits/stdc++.h>
using namespace std;
char ans[101];
int n;
int main() {
	for(int tc = 1; tc <= 10; ++tc) {
		string s;
		cin >> n;
		cin >> s;
		int p = 0;
		ans[0] = s[0];
		for(int i = 1; i < s.size(); ++i) {
			if(s[i] == ans[p]) {
				ans[p--] = '\0';
			} else ans[p++ + 1] = s[i];
		}
		ans[p + 1] = '\0';
		cout << '#' << tc << ' ' << ans << '\n';
	}
}

//»ý·«