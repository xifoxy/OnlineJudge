#include <bits/stdc++.h>
using namespace std;
string s, ans;
int main() {
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		ans.push_back(s[i]);
		while(i < s.size() && s[i] != '-')
			++i;
	}
	cout << ans;
}

// 말하지 않아도 알아요~