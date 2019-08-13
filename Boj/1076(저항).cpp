#include <bits/stdc++.h>
using namespace std;
string ans, cmd, str[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
char getidx(string &s) {
	char ch;
	for(int i = 0; i < 10; ++i) {
		if(str[i] == s)
			ch = i + 48;
	}
	return ch;
}
int main() {
	cin >> cmd;
	ans.push_back(getidx(cmd));
	if(ans.back() == '0') ans.pop_back();
	cin >> cmd;
	ans.push_back(getidx(cmd));
	cin >> cmd;
	int cnt = getidx(cmd) - 48;
	for(int i = 0; i < cnt; ++i)
		ans.push_back('0');
	if(ans.size() && ans[0] == '0') cout << '0';
	else cout << ans;
}

// 그냥 노가다.