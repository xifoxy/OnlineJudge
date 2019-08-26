#include <bits/stdc++.h>
using namespace std;
string str;
stack<char> st;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);	
	cin >> str >> n;
	for(int i = 0; i < n; ++i) {
		char ch;
		cin >> ch;
		if(ch == 'B' && str.size()) str.pop_back();
		else if(ch == 'D' && st.size() != 0) {
			str.push_back(st.top());
			st.pop();
		} else if(ch == 'L' && str.size() != 0) {
			st.push(str.back());
			str.pop_back();
		} else if(ch == 'P') {
			cin >> ch;
			str.push_back(ch);
		}
	}
	while(st.size() != 0) {
		str.push_back(st.top());
		st.pop();
	}
	cout << str;
}

// 설명(Stack)
// 스택 두개를 이용하여 푼 문제이다.
// 답을 편하게 출력하기 위해 스택하나는 string클래스로 대체 했다.
// 커서가 움직였을때의 상황을 재현하기 위해 스택을 두개 이용한 것이니
// 곰곰히 한번 생각해보자.