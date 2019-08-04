#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string str, ans = "";
	cin >> str;
	stack<char> st;
	for(int i = 0; i < str.size(); ++i) {
		if(str[i] == '(') st.push('(');
		else if(str[i] == ')') {
			while(st.top() != '(') {
				ans.push_back(st.top());
				st.pop();
			} st.pop();
		} else if(str[i] == '/' || str[i] == '*') {
			while(st.size() && (st.top() == '/' || st.top() == '*')) {
				ans.push_back(st.top());
				st.pop();
			} st.push(str[i]);
		} else if(str[i] == '-' || str[i] == '+') {
			while(st.size() && st.top() != '(') {
				ans.push_back(st.top());
				st.pop();
			} st.push(str[i]);
		} else ans.push_back(str[i]);
	}
	while(st.size()) {
		ans.push_back(st.top());
		st.pop();
	}
	cout << ans;
}

//설명
//쉬워보이나 우선순위가 중요한 문제다.
//크게 두가지 분류로 나뉠수 있는데
//1. 사칙연산을 만났을경우
//2. 닫힌 괄호를 만났을 경우

//우선 사친연산을 만났을 경우이다. 
//[1] = 곱하기, 나누기	[2] = 빼기, 더하기
//[1]이 나오게 되면 또다른 [1]이 나올때까지 답을 만들어 줘야 한다.
//A+B+C+D*A*B라는 경우를 잘 생각해보자.
//[2]를 만났을경우에는 열린괄호만을 염두에 두고 답을 완성해주면 된다.

//닫힌 괄호를 만나게 되면 짝이 되는 열린괄호까지 연산을 해주면된다.