#include <bits/stdc++.h>
using namespace std;
const int MX = 2200;
string s;
int n, ans;
int d[37];
int main() {
	cin >> s >> n;
	d[1] = n;
	for(int i = 2; i < s.size(); ++i) {
		d[i] = d[i - 1] * n;
	}
	reverse(s.begin(), s.end());
	for(int i = 0; i < s.size(); ++i) {
		int t = 0;
		if(s[i] >= '0' && s[i] <= '9')
			t += s[i] - '0';
		else t += s[i] - 'A' + 10;
		if(!i) ans += t;
		else ans += (t * d[i]);
	}
	cout << ans;
}

// 설명
// 깡구현이다. N진법이면 자릿수마다 값을 구해주면 된다.
// 자리값을 토대로 문자값을 숫자로 치환해서 곱해주면 그 자리의 값이 된다.