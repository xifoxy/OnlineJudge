#include <bits/stdc++.h>
using namespace std;
string s[50], ans;
int n;
int main() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> s[i];

	ans = s[0];
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < ans.size(); ++j) {
			if(ans[j] != s[i][j]) ans[j] = '?';
		}
	}
	cout << ans;
}

//����