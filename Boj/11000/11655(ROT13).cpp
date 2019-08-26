#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
	getline(cin, s);
	for(int i = 0; i < s.size(); ++i) {
		int t = s[i] + 13;
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] = t > 'Z' ? 'A' + (t - 'Z' - 1) : t;
		else if(s[i] >= 'a' && s[i] <= 'z')
			s[i] = t > 'z' ? 'a' + (t - 'z' - 1) : t;
	}
	cout << s;
}