#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
	cin >> s;
	int idx = 0, ans = 0, len = s.size();
	while(idx < len) {
		ans++;
		int n = idx + 1;
		if(s[n - 1] == 'c') {
			if(n < len && (s[n] == '-' || s[n] == '='))
				++idx;
		} else if(s[n - 1] == 'd') {
			if(n < len && s[n] == '-') ++idx;
			else if(n + 1 < len && s[n] == 'z' && s[n + 1] == '=') idx += 2;
		} else if(n < len && s[n - 1] == 'l' && s[n] == 'j') ++idx;
		else if(n < len && s[n - 1] == 'n' && s[n] == 'j') ++idx;
		else if(n < len && s[n - 1] == 's' && s[n] == '=') ++idx;
		else if(n < len && s[n - 1] == 'z' && s[n] == '=') ++idx;
		++idx;
	}
	cout << ans;
}

// AH SAY~ 말하지 않아도 알아요~