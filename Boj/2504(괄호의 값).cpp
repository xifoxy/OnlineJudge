#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string str;
	stack<char> st;
	cin >> str;
	int mul = 1, ans = 0;
	for(int i = 0; i < str.size(); ++i) {
		if(str[i] == '(' || str[i] == '[') {
			st.push(str[i]);
			mul *= str[i] == '(' ? 2 : 3;
		}
		else if(st.size() == 0 || (str[i] == ')' && st.top() != '(') || (str[i] == ']' && st.top() != '[')) {
			ans = 0;
			break;
		} else {
			if(str[i - 1] == '[' || str[i - 1] == '(') ans += mul;
			st.pop();
			mul /= str[i] == ')' ? 2 : 3;
		}
	}
	cout << (st.size() ? 0 : ans);
}

//설명
//내부 괄호의 값을 일일이 다 계산하려고 하면 연산이 제법 골아파진다.
//그러니 발상을 바꿔서 괄호를 만날대마다 열린괄호를 만날때마다 곱해주고
//닫힌 괄호를 만날때 처리해주면 된다.

//이해가 안된다면. 우선 이것부터..
//2 * (3 + 3) = (2 * 3) + (2 * 3)