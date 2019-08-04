#include <bits/stdc++.h>
using namespace std;
int n;
string s[100];
bool d(int x, int y, int len) {
	if(x + len - 1 >= 100) return false;
	int l = x, r = x + len - 1;
	while(l <= r) {
		if(s[l++][y] != s[r--][y]) return false;
	}
	return true;
}
bool r(int x, int y, int len) {
	if(y + len - 1 >= 100) return false;
	int l = y, r = y + len - 1;
	while(l <= r) {
		if(s[x][l++] != s[x][r--]) return false;
	}
	return true;
}
int main() {
	for(int tc = 1; tc <= 10; ++tc) {
		int ans = 0;
		cin >> n;
		for(int i = 0; i < 100; ++i)
			cin >> s[i];
		for(int i = 0; i < 100; ++i) {
			for(int j = 0; j < 100; ++j) {
				for(int k = 1; k <= 100; ++k) {
					if(r(i, j, k)) ans = max(ans, k);
					if(d(i, j, k)) ans = max(ans, k);
				}
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}

//»ý·«