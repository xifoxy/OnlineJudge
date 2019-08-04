#include <bits/stdc++.h>
using namespace std;
int t, i, n, m, j, Scnt;
int main() {
	cin >> t;
	string str;
	for(; i < t; ++i) {
		m = Scnt = 0;
		bool iSeen[10]{false,};
		cin >> n;
		while(1) {
			m += n;
			str = to_string(m);
			for(j = 0; j < str.length(); ++j) if(!iSeen[str[j] - '0']) {
				iSeen[str[j] - '0'] = true;
				Scnt++;
			}
			if(Scnt == 10) break;

		}
		cout << '#' << i + 1 << ' ' << m << '\n';
	}
}

//»ý·«