#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
int main() {
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		ans.push_back(s.substr(i, s.size()));
	}
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << '\n';
}

//»ý·«