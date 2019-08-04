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

//설명
//구현하기 귀찮으니까 그냥 transform을 이용해서 전부다 대문자로 만들어버리자.