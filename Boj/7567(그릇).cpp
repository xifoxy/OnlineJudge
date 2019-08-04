#include <bits/stdc++.h>
using namespace std;
int main(){
	stack<char> st;
	string str;
	cin >> str;

	int ans = 10;
	st.push(str[0]);
	for(int i = 1; i < str.size(); ++i){
		if(str[i] == '(') ans += st.top() == ')' ? 10 : 5;
		else ans += st.top() == '(' ? 10 : 5;
		st.push(str[i]);
	}
	cout << ans << '\n';
}

// 생략