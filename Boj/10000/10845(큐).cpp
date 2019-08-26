#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int tc, n;
int main() {
	cin >> tc;
	while(tc--) {
		string cmd;
		cin >> cmd;
		if(cmd[1] == 'u') cin >> n, q.push(n);
		else if(cmd[1] == 'o') {
			if(!q.empty()) cout << q.front() << '\n', q.pop();
			else cout << -1 << '\n';
		} else if(cmd[0] == 's') cout << q.size() << '\n';
		else if(cmd[0] == 'e') cout << (q.size() ? 0 : 1) << '\n';
		else if(cmd[0] == 'f') cout << (q.size() ? q.front() : -1) << '\n';
		else cout << (q.size() ? q.back() : -1) << '\n';
	}
}

//»ý·«