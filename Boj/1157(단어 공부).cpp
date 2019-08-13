#include <bits/stdc++.h>
using namespace std;
int ch[26], mx, cnt, idx;
string s;
int main() {
	cin >> s;
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	for(int i = 0; i < s.size(); ++i) {
		ch[s[i] - 'A']++;
		mx = max(ch[s[i] - 'A'], mx);
	}
	for(int i = 0; i < 26; ++i) {
		if(ch[i] == mx) {
			cnt++;
			idx = i;
		}
	}
	if(cnt > 1) cout << "?";
	else cout << (char)(idx + 'A');
}

// 쉽다.
// 알파벳이 나오는 갯수를 메모 해뒀다가 답을 도출하면된다.