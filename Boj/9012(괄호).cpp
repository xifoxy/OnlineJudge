#include <bits/stdc++.h>
using namespace std;
int n;
string str;
bool sol() {
	bool ret = false;
	if(str.size() % 2 || str[0] == ')')
		return ret;
	stack<char> st; st.push(str[0]);
	for(int i = 1; i < str.size(); ++i) {
		if(str[i] == ')') {
			if(st.size() && st.top() == '(') {
				st.pop();
				continue;
			} else return ret;
		} st.push(str[i]);
	}
	if(!st.size()) ret = true;
	return ret;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> str;
		if(sol()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}

//½±´Ù