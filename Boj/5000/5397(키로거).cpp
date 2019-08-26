#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	string s;
	while(t--) {
		cin >> s;
		deque<char> L, R;
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == '<') {
				if(L.size())
					R.push_front(L.back()), L.pop_back();
			} else if(s[i] == '>') {
				if(R.size())
					L.push_back(R.front()), R.pop_front();
			} else if(s[i] == '-') {
				if(L.size()) L.pop_back();
			} else L.push_back(s[i]);
		}
		for(int i = 0; i < L.size(); ++i)
			cout << L[i];
		for(int i = 0; i < R.size(); ++i)
			cout << R[i];
		cout << '\n';
	}
}


//설명
//어렵지 않다 방향키가 나올때마다 좌 우로 분배해서 FIFO가 가능한 자료구조에 넣어주고
//왼쪽에 다 때려박아넣으면 된다.

//<<BP<AP><<CD- (문제 예시랑 다름)
//LEFT = BP, RIGHT = NULL
//LEFT = B, RIGHT = P
//LEFT = BAP, RIGHT = P
//LEFT = BAPP, RIGHT = NULL
//LEFT = BA, RIGHT = PP
//LEFT = BACD, RIGHT = PP
//LEFT = BAC, RIGHT = PP
//BACPP