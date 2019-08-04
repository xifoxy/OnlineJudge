#include <bits/stdc++.h>
using namespace std;
stack<int> st;
string cmd;
int tc, a;
int main() {
	cin >> tc;
	while(tc--) {
		cin >> cmd;
		if(cmd[1] == 'u')
			cin >> a, st.push(a);
		else if(cmd[0] == 't') {
			cout << (st.empty() ? -1 : st.top()) << '\n';

		} else if(cmd[0] == 'e')
			cout << (st.empty() ? 1 : 0) << '\n';
		else if(cmd[0] == 's') cout << st.size() << '\n';
		else {
			if(st.empty()) cout << -1 << '\n';
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
	}
}

//»ý·«