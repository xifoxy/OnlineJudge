#include <bits/stdc++.h>
using namespace std;
int d[3] = {4,1,2}, t;
int main() {
	string st, ans;
	cin >> st;
	int x = st.size() % 3;
	for(int i = 0; i < st.size(); ++i) {
		if(st[i] == '1') t += (d[x] * 1);
		if(x == 1) {
			ans.push_back(t + '0');
			t = 0;
		}
		x = x == 0 ? 2 : x - 1;
	}
	cout << ans << '\n';
}

// 설명
// 1212번 문제를 뒤집으면 된다.