#include <bits/stdc++.h>
using namespace std;
int n, num;
string s;
typedef pair<char, int> P;
int main() {
	cin >> n;
	map<P, int> mp;
	deque<P> st;
	stack<P> temp;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 5; ++j) {
			cin >> s;
			P t;
			t.first = s[0];
			t.second = stoi(s.substr(2, s.size() - 2));
			mp[t] = 0;
			st.push_back(t);
		}
	}

	int rank = 1, idx = 0;
	for(map<P, int>::iterator it = mp.begin(); it != mp.end(); ++it)
		it->second = rank++;

	rank = 1;
	bool ans = true;
	while(st.size()) {
		P t, t2;
		t = st.front();
		st.pop_front();
		if(mp[t] == rank) {
			++rank;
			continue;
		}
		while(temp.size() && mp[temp.top()] == rank) {
			temp.pop();
			rank++;
		}
		if(mp[t] == rank) {
			++rank;
			continue;
		}
		if(temp.size() && mp[t] > mp[temp.top()]) {
			ans = false;
			break;
		}
		temp.push(t);
	}
	cout << (ans ? "GOOD" : "BAD");
}

//설명
//충남콘테스트 F번 문제이다.
//정렬(랭킹), 스택의 개념이 필요하기에 코드를 저장해둔다.