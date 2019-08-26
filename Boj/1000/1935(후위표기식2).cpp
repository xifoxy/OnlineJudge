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

// ����
// ����ǥ����� Ǯ������ ��ü�ϴ°� �״��� ����� �ʴ�.
// ��Ģ������ ���������� ���ÿ� �����ϴ� ������ ������ ��� �ȴ�.