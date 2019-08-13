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

// 설명(문자열 처리)
// 어려워 보이지만 그냥 아무 문자열이나 하나를 잡고
// 공통된 부분만 남겨두고 전부다 '?'로 바꿔주면 된다.