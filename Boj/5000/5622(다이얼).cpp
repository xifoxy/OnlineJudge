#include <bits/stdc++.h>
using namespace std;
int d[]{2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9}, ans;
string s;
int main() {
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		ans += d[s[i] - 'A'] + 1;
	}
	cout << ans;
}

//»ý·«