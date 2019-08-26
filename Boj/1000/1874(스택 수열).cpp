#include <bits/stdc++.h>
using namespace std;
int n, a, d[100001], idx, num;
int main() {
	string ans = "";
	cin >> n;
	stack<int> st;
	for(int i = 0; i < n; ++i)
		cin >> d[i];


	while(idx < n) {
		// 스택에 N + 1 까지 숫자가 들어갔거나,
		// 스택 최상단에 있는 숫자가 출력해야할 숫자보다 크다면 불가능한 경우다.
		if(num > n || (st.size() && st.top() > d[idx])) break;

		// 현재 스택 최상단에 있는 숫자가 출력해야 할 숫자라면 스택에 있는 숫자를 뽑아낸다.
		if(st.size() && st.top() == d[idx]) {
			st.pop();
			ans.push_back('-');
			++idx;
		}
		// 스택이 비었거나, 스택상단에 있는 숫자가 출력해야할 숫자보다 크다면
		// 다음 숫자를 넣는다.
		else if(st.size() == 0 || (st.top() <= d[idx])) {
			st.push(++num);
			ans.push_back('+');
		}
	}
	if(st.size()) cout << "NO";
	else for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << '\n';
}

// 설명(Stack)
// 1~N으로 주어진 Input값 순서대로 수열을 만드는 문제이다.
// 그리디한 문제다. 스택에 숫자를 순차적으로 쌓아가다가 출력해야할 숫자와 일치한다면 그 숫자를 빼주면 된다.