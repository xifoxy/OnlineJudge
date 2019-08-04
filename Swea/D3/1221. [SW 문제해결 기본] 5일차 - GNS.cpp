#include <bits/stdc++.h>
using namespace std;
string s, tcc;
string lang[10] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};
int d[11], t, n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	for(int tc = 1; tc <= t; ++tc) {
		memset(d, 0, sizeof(d));
		cin >> tcc;
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin >> s;
			if(s[0] == 'Z') d[0]++;
			else if(s[0] == 'O') d[1]++;
			else if(s[0] == 'T') s[1] == 'W' ? d[2]++ : d[3]++;
			else if(s[0] == 'F') s[1] == 'O' ? d[4]++ : d[5]++;
			else if(s[0] == 'S') s[1] == 'I' ? d[6]++ : d[7]++;
			else if(s[0] == 'E') d[8]++;
			else d[9]++;
		}
		cout << tcc << '\n';
		for(int i = 0; i < 10; ++i) {
			for(int j = 0; j < d[i]; ++j) {
				cout << lang[i] << ' ';
			}
		}
		cout << '\n';
	}
}

//»ý·«