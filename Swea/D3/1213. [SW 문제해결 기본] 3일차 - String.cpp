#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
	for(int tc = 1; tc <= 10; ++tc) {
		cin >> t;
		string s, s2;
		int ans = 0;
		cin >> s >> s2;
		size_t pos = 0;
		while((pos = s2.find(s, pos)) != string::npos) {
			pos += s.size();
			ans++;
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
}

//»ý·«