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

// ����.
// ���ĺ��� ������ ������ �޸� �ص״ٰ� ���� �����ϸ�ȴ�.