#include <bits/stdc++.h>
using namespace std;
int d[13]{0,31,28,31,30,31,30,31,31,30,31,30,31}, t, i;
int main() {
	cin >> t;
	for(; i < t; ++i) {
		string YMD; cin >> YMD;
		int month, day;
		month = stoi(YMD.substr(4, 2));
		day = stoi(YMD.substr(6, 2));
		if(month != 0 && d[month] >= day && day != 0) {
			cout << '#' << i + 1 << ' ' << YMD.substr(0, 4) << '/' << YMD.substr(4, 2) << '/' << YMD.substr(6, 2);
		} else cout << '#' << i + 1 << ' ' << -1;
		cout << '\n';
	}
}

//»ý·«