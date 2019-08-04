#include <bits/stdc++.h>
using namespace std;
int tc, ans;
int main(){
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		
		stack<char> st;
		st.push(str[0]);
		for(int i = 1; i < str.size(); ++i){
			if(!st.empty() && st.top() == str[i])
				st.pop();
			else st.push(str[i]);
		}

		if(st.empty()) ans++;
	}
	cout << ans;
}

// 설명(Stack)
// 간단한 스택문제이다. 
// A라는 괄호와 B라는 짝을 이루었는지 확인하는 문제이다.

// (({{}}))({}()) 올바른 괄호와
// ({)} 올바르지 않은 괄호