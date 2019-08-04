#include <bits/stdc++.h>
using namespace std;
int main() {
	set<string> st;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string pass;
		cin >> pass;
		st.insert(pass);
		reverse(pass.begin(), pass.end());
		if(st.find(pass) != st.end()) {
			cout << pass.size() << ' ' << pass[pass.size() / 2];
			break;
		}
	}
}

// 설명
// if(i == 0) continue 했다가 오답을 맞았다.
// 테케로 트릭을 만들어 놨는데.. 주어진 케이스 자체가 팰린드롬이라면ㅋㅋㅋ