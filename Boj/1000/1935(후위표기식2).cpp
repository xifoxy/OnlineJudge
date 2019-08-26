#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	double d[26] = {0,};
	int n;
	string str;
	cin >> n >> str;

	stack<double> st;
	for(int i = 0; i < n; ++i)
		cin >> d[i];
	for(int i = 0; i < str.size(); ++i) {
		if(str[i] >= 'A' && str[i] <= 'Z')
			st.push(d[str[i] - 'A']);
		else {
			double t = st.top(); st.pop();
			if(str[i] == '*') st.top() *= t;
			else if(str[i] == '/') st.top() /= t;
			else if(str[i] == '+') st.top() += t;
			else st.top() -= t;
		}
	}
	printf("%.2lf", st.top());
}

// 설명
// 후위표기식을 풀었으면 해체하는건 그다지 어렵지 않다.
// 사칙연산이 있을때마다 스택에 존재하는 값으로 가지고 놀면 된다.