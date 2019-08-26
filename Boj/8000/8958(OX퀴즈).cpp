#include <bits/stdc++.h>
using namespace std;
string s;
int tc, sum;
int main() {
	cin >> tc;
	while(tc--) {
		cin >> s;
		sum = 0;
		for(int i = 0, cnt = 0; i < s.size(); ++i) {
			cnt = s[i] == 'O' ? cnt + 1 : 0;
			sum += cnt;
		}
		cout << sum << '\n';
	}
}

//»ý·«