#include <bits/stdc++.h>
using namespace std;
int n;
string s[8];
bool d(int x, int y) {
	if(x + n - 1 >= 8) return false;
	int l = x, r = x + n - 1;
	while(l <= r) {
		if(s[l++][y] != s[r--][y]) return false;
	}
	return true;
}
bool r(int x, int y) {
	if(y + n - 1 >= 8) return false;
	int l = y, r = y + n - 1;
	while(l <= r) {
		if(s[x][l++] != s[x][r--]) return false;
	}
	return true;
}
int main() {
	for(int tc = 1; tc <= 10; ++tc) {
		int ans = 0;
		cin >> n;
		for(int i = 0; i < 8; ++i)
			cin >> s[i];
		for(int i = 0; i < 8; ++i) {
			for(int j = 0; j < 8; ++j) {
				if(r(i, j)) ans++;
				if(d(i, j)) ans++;
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}

//»ý·«